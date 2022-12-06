#include "index_of_pipe.h"



int index_of_pipe(char *buff){
    int count = 0;
    while(*buff != '\0' && *buff != '|'){
        buff++;
        count++;
    }
    if(*buff == '\0'){
        return -1;
    }
    return count;
}