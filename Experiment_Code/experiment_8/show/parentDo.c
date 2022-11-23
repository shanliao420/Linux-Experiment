#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parentDo.h"


void parentDo(int pid, int status){
    if (pid = waitpid(pid, status, 0) < 0)
        printf(" pid error!");
}