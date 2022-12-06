#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "show/getCommand_parse.h"
#include "show/getCommand_readKey.h"
#include "show/showPrompt.h"
#include "process/fork.h"
#include "process/index_of_pipe.h"
#include "process/parent_process.h"
#define MAXSIZE 4096

int main(int argc, char const *argv[], char *env[])
{
    int ppipe[2];
    int pid1, pid2;
    char buff[MAXSIZE];
    char *buff_2;
    char *args_1[64];
    char *args_2[64];
    int arg_nums = 0;
    int pipe_flag = 0;

    printf("\n\n\t Welcom to Google Future Leaders very Power Shell System!\n\n");
    while(1){
        showPrompt();
        readKey(buff);
        if(!strcmp(buff, "\n")){
            continue;
        }

        if((pipe_flag = index_of_pipe(buff)) != -1){
            pipe(ppipe);
            buff[pipe_flag] = 0; // instead '|' whit '\0'
            buff_2 = &buff[pipe_flag + 1];
            parse(buff_2, args_2);
        }

        parse(buff, args_1);
        
        if(!strcmp(args_1[0],"exit")){
            exit(0);
        }

        if((pid1 = fork()) == 0){
            fork_1(args_1[0], args_1, pipe_flag, ppipe);
        }
        if(pipe_flag != -1){
            if((pid2 = fork()) == 0){
                fork_2(args_2[0], args_2, ppipe);
            }
        }
        parent_process(pid1, pid2, pipe_flag, ppipe);
    }




    return 0;
}
