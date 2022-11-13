#include <stdio.h>
#include <string.h>
#include "is_l.h"
#include "get_opt_size.h"

// 判断是否有-l 参数 有返回1 无返回0
int is_l(int argc, char const *argv[]){
    if(get_opt_size(argc) >= 1){
        if(!strcmp("-l", argv[1])){
            return 1;
        }
    }
    return 0;
}



// int main(int argc, char const *argv[])
// {
//     if(is_l(argc, argv)){
//         printf("have -l parameter\n");
//     }else{
//         printf("no -l parameter\n");
//     }


//     return 0;
// }
