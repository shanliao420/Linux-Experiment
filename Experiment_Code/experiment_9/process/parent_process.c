#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parent_process.h"

void wait_child(int pid){
    if (pid = waitpid(pid, NULL, 0) < 0)
        printf(" pid error!");
}

void parent_process(int pid1, int pid2, int pipe_flag, int ppipe[]){
    if(pipe_flag != -1){
        close(ppipe[0]);
        close(ppipe[1]);
    }

    wait_child(pid1);

    if(pipe_flag != -1){
        wait_child(pid2);
    }
}