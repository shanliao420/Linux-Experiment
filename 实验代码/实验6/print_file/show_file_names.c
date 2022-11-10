#include <stdio.h>
#include "show_file_names.h"


void show_file_names(char* path){
    printf("printf all of the dir's file-names\n");
}



int main(int argc, char const *argv[])
{
    char path[] = "./";
    show_file_names(path);


    return 0;
}
