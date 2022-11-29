#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "getCommand_readKey.h"
#define MAXSIZE 4096


void readKey(char* buff){
    char* ret;
    ret = fgets(buff, MAXSIZE, stdin);
    if(ret == NULL){
        printf("error occurs!\n");
        exit(1);
    }
    if(buff[strlen(buff) - 1] == "\n"){
        buff[strlen(buff) - 1] = 0;
    }
    
}


// int main(int argc, char const *argv[])
// {
    
//     char buff[MAXSIZE];
//     readKey(buff);
//     printf("the buff is %s\n", buff);

//     return 0;
// }
