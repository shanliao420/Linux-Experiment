#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>


int char_to_int(const char* str, int size){
    int ans = 0;
    for(int i = 0; i < size; i++){
        ans = ans * 10 + str[i] - '0';
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    // argv[0] = ./a.out
    // argv[1] = file1
    // argv[2] = file2
    
    const char* start_file_path = argv[1];
    const char* to_file_path = argv[2];

    int BUFFSIZE = char_to_int(argv[3], 3);
    //printf("argv[3] = %s, buffsize = %d, sizeof(argv[3]) = %d ", argv[3], BUFFSIZE, sizeof(argv[3])/sizeof(char) );
    
    int start_description = open(start_file_path, O_RDONLY);
    int to_description = open(to_file_path, O_RDWR | O_TRUNC | O_CREAT, 0644);
    if(start_description == -1 || to_description == -1){
        perror("open");
        exit(1);
    }
    char* buff = malloc(sizeof(char) * BUFFSIZE);
    long allCnt = 0;
    int readSize = 0;
    //printf("sizeof(buff) =  %d\n", sizeof(buff))
    size_t time_start = clock();
    while((readSize = read(start_description, buff, sizeof(buff))) > 0){
        allCnt += readSize;
        if(write(to_description, buff, readSize) == - 1){
            perror("write");
            exit(1);
        }
    }
    printf("when BUFFSIZE is %d, using time %d ! copy %ld bytes in all !\n", BUFFSIZE, clock() - time_start, allCnt);

    close(start_description);
    close(to_description);
    free(buff);






    return 0;
}
