#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "process/getCommand_parse.h"
#include "process/getCommand_readKey.h"
#include "process/showPrompt.h"
#include "show/childDo.h"
#include "show/parentDo.h"
#define MAXSIZE 4096


int main(int argc, char const *argv[], char *env[])
{
    int pid;
    int status;
    char buff[MAXSIZE];
    char *args[64];
    int arg_nums = 0;

    printf("\n\n\t Welcom to Google Future Leaders very Power Shell System!\n\n");
    while(1){
        showPrompt();
        readKey(buff);
        if(!strcmp(buff, "\n")){
            continue;
        }

        arg_nums = parse(buff, args);
        // printf("arg_nums = %d : ", arg_nums);
        // for(int i = 0; i < arg_nums; i++){
        //     printf("%s\t", args[i]);
        // }
        // printf("\n");

        if(!strcmp(args[0],"exit")){
            exit(0);
        }

        pid = fork();
        if(pid < 0){
            printf("fork error!\n");
            continue;
        }else if (pid == 0)
        {
            char cmd[64] = "/bin/";
            strcat(cmd, args[0]);
            // printf("the cmd is %s\n", cmd);
            childDo(cmd, args, env);
        }

        parentDo(pid, &status);
        
    }




    return 0;
}
