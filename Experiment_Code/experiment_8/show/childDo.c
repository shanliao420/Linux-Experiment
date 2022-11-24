#include <stdio.h>
#include <unistd.h>
#include "childDo.h"


void childDo(char* command, char** args){
    execvp(command, args);
    printf("could not execute %s\n", command);
    exit(127);
}



// int main(int argc, char const *argv[])
// {
//     char *args[3] = {"ps"};
//     childDo(*args, args);
//     return 0;
// }
