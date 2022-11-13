#include <stdio.h>
#include "get_path.h"

char* get_path(int argc, char const *argv[]){
    return argv[argc - 1];
}



// int main(int argc, char const *argv[])
// {
//     printf("the input path is %s\n", get_path(argc, argv));
//     return 0;
// }
