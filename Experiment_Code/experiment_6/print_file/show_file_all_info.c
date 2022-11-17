#include <stdio.h>
#include "show_file_all_info.h"

void show_file_all_info(char* path){
    // 对每一个文件或目录执行print_long
}

// 打印一个文件或目录的长格式
void print_long(char* file){
    printf("prinf all info of file\n");
}



int main(int argc, char const *argv[])
{
    char* path = "./";
    show_file_all_info(path);
    return 0;
}
