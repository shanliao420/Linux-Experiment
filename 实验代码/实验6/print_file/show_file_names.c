#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include "show_file_names.h"


void show_file_names(char dirname[])
{
    DIR *dir_ptr;//文件夹指针
    struct dirent *direntp;//存放文件夹目录内容

    if((dir_ptr = opendir(dirname)) == NULL){//open环节
        fprintf(stderr, "ls1: open error %s\n",dirname);//打开失败
    }else{
        while((direntp = readdir(dir_ptr)) != NULL){//while（readdir）
            printf("%s\n",direntp -> d_name);//d_name:当前遍历子项的文件名，限制长度为256，包括字符串终止符’\0’
        }
        int flag;
        if(( flag = closedir(dir_ptr)) == -1){//close环节
            perror("ls1: close dir error");//关闭失败
            exit(0);
        }
 }
}



int main(int argc, char const *argv[])
{
    char path[] = "./";
    show_file_names(path);


    return 0;
}
