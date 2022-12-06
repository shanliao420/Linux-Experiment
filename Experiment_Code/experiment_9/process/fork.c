#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "fork.h"

void fork_1(char* command, char** args, int pipe_flag, int ppipe[]){
    if(pipe_flag != -1){
        dup2(ppipe[1], 1);
        close(ppipe[0]);
        close(ppipe[1]);
    }
    execvp(command, args);
    printf("could not execute %s\n", command);
    exit(127);
}

void fork_2(char* command, char** args, int ppipe[]){
    dup2(ppipe[0], 0);
    close(ppipe[0]);
    close(ppipe[1]);
    execvp(command, args);
    printf("could not execute %s\n", command);
    exit(127);
}



// int main(int argc, char const *argv[])
// {
//     char *args[3] = {"ps"};
//     fork_1(*args, args, -1);
//     return 0;
// }
