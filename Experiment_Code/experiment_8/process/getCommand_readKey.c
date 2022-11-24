#include <stdio.h>
#include <unistd.h>
#include "getCommand_readKey.h"
#define MAXSIZE 4096


void readKey(char* buff){
    char* ret;
    ret = fgets(buff, MAXSIZE, stdin);
    if(ret == NULL){
        printf("error occurs!\n");
        exit(1);
    }
}


// int main(int argc, char const *argv[])
// {
    
//     char buff[MAXSIZE];
//     readKey(buff);
//     printf("the buff is %s\n", buff);

//     return 0;
// }
