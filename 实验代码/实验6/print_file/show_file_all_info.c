#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <linux/fs.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include "show_file_all_info.h"

int typeflag;
void gettype(char *name)
{
struct stat buf;
lstat(name,&buf);
switch(buf.st_mode&S_IFMT)
	{
	case S_IFREG:
		typeflag=1;
                break;
        case S_IFDIR:
                typeflag=2;
                break;       
       	case S_IFLNK:
                typeflag=3;
                break;
	case S_IFCHR:
                typeflag=4;
                break;       
       	case S_IFBLK:
                typeflag=5;
                break;    
    	case S_IFSOCK:
                typeflag=6;
                break;
	case S_IFIFO:
                typeflag=7;
                break;
	default:
		typeflag=0;
	}
if(typeflag==1)
	{
	print_long(name);
	}
else if(typeflag==2)
	{
	lsdir(name);
	}
else
	printf("cannot print this type");
}

void lsdir(char *name)
{
DIR *d1;
struct dirent *dent1;
char namebuf[128];
char workdir[50];
d1=opendir(name);
if(d1==NULL)
	{
	perror("opendir");
	exit(1);
	}
getcwd(workdir,50);
chdir(name);
errno=0;
dent1=readdir(d1);
while(dent1!=NULL)
	{
	if(dent1->d_name[0]!='.')
		{
		print_long(dent1->d_name);
		}
	dent1=readdir(d1);
	}
if(errno!=0)
	perror("readdir");
closedir(d1);
chdir(workdir);
}

void print_size(struct stat *statp)
{
 
 switch(statp->st_mode & S_IFMT)
 {
  case S_IFCHR:
  case S_IFBLK:
   printf("%u,%u",(unsigned)(statp->st_rdev>>8),(unsigned)(statp->st_rdev&0xFF));
   break;
  default:
   printf("%lu",(unsigned long)(statp->st_size));
 }
}

void print_long(char *name)
{
 struct stat buf;
 struct passwd *user;
 struct group *grp;
 char linkname[64];
 char dirfilename[64];
 int rt;
 rt=lstat(name,&buf);
 if(-1==rt)
 {
  perror("in print_long:lstat");
  return;
 }

 switch(buf.st_mode&S_IFMT)
 {
  case S_IFDIR:
   printf("d");
   break;
  case S_IFLNK:
   printf("l");
   break;
  case S_IFREG:
   printf("-");
   break;
  case S_IFBLK:
   printf("b");
   break;
  case S_IFCHR:
   printf("c");
   break;
  case S_IFSOCK:
   printf("s");
   break;
  case S_IFIFO:
   printf("p");
   break;
  default:
   printf("?");
   break;
 }

 putchar((buf.st_mode&S_IRUSR)?'r':'-');
 putchar((buf.st_mode&S_IWUSR)?'w':'-');
 if(buf.st_mode&S_ISUID)
 {
  putchar((buf.st_mode&S_IXUSR)?'s':'S');
 }
 else
 {
  putchar((buf.st_mode&S_IXUSR)?'x':'-');
 }

 putchar((buf.st_mode&S_IRGRP)?'r':'-');
 putchar((buf.st_mode&S_IWGRP)?'w':'-');
 if(buf.st_mode&S_ISGID)
 {
  putchar((buf.st_mode&S_IXGRP)?'s':'S');
 }
 else
 {
  putchar((buf.st_mode&S_IXGRP)?'x':'-');
 }
 
 putchar((buf.st_mode&S_IROTH)?'r':'-');
 putchar((buf.st_mode&S_IWOTH)?'w':'-');
 if(buf.st_mode&S_ISVTX)
 {
  putchar((buf.st_mode&S_IXOTH)?'t':'T');
 }
 else
 {
  putchar((buf.st_mode&S_IXOTH)?'x':'-');
 }

 printf("%2u",buf.st_nlink);
 
 user=getpwuid(buf.st_uid);

 printf("\t%s",user->pw_name);

 grp=getgrgid(buf.st_gid);
 
 printf("\t%s\t",grp->gr_name);

 print_size(&buf);
 
 print_date(&buf);
 
 if(typeflag==3)
 {
  rt=readlink(name,linkname,sizeof(linkname));
  linkname[rt]=0;
  printf("\t%s->%s",name,linkname);
 }
 else
 {
  printf("\t%s",name);
 }
 printf("\n");
}

void print_date(struct stat *statp)
{
 time_t now;
 double diff;
 char buf[100],*fmt;
 if(time(&now)==-1)
	 {
 	 printf("????????????");
 	 return;
	 }
 
 diff=difftime(now,statp->st_mtime);
 if(diff<0||diff>60*60*24*128.5)
   	fmt="%Y-%m-%d";
 else
   	fmt="%Y-%m-%d %H:%M";
 
 strftime(buf,sizeof(buf),fmt,localtime(&statp->st_mtime));
 printf("\t%s",buf);
}

void show_file_all_info(char* path){
    gettype(path);
}



int main(int argc, char const *argv[])
{
    char* path = "./";
    show_file_all_info(path);
    return 0;
}
