#include <stdio.h>
#include "is_l.h"

// 判断是否有-l 参数 有返回1 无返回0
int is_l(char const *argv[]){
    return 1;
}



int main(int argc, char const *argv[])
{
    if(is_l(argv)){
        printf("have -l parameter\n");
    }else{
        printf("no -l parameter\n");
    }


    return 0;
}
