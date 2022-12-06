#include <stdio.h>
#include "getCommand_parse.h"


int parse(char *buff, char** args){
    int num = 0;
	while(*buff!='\0')
	{
		while((*buff==' ')||(*buff=='\t'||(*buff=='\n')))
			*buff++='\0';
		*args++=buff;
        ++num;
		while((*buff!='\0')&&(*buff!=' ')&&(*buff!='\t')&&(*buff!='\n'))
			buff++;
	}
	*(--args)='\0';
    return num - 1;
}


// int main(int argc, char const *argv[])
// {
//     char buff[] = "ls -l /root/home/";
//     char *args[64];
//     int argsnum = parse(buff, args);
//     printf("the args num is %d\n", argsnum);

//     for(int i = 0; i < argsnum; i++){
//         printf("%s\n", args[i]);
//     }



//     return 0;
// }

