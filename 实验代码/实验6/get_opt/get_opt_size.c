#include <stdio.h>
#include "get_opt_size.h"

int get_opt_size(int argc){
    // 返回除ls命令本身参数个数
    return argc - 1;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", get_opt_size(argc));
    return 0;
}
