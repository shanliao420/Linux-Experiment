#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "childDo.h"


void childDo(char* command, char** args, char** env){
    execve(command, args, env);
    printf("could not execute %s\n", command);
    exit(127);
}



// int main(int argc, char const *argv[])
// {
//     char *args[3] = {"ps"};
//     childDo(*args, args);
//     return 0;
// }
