#ifndef _INFO_H_
#define _INFO_H_
#include <stdio.h>
#include <sys/stat.h>
void gettype(char *);
void lsdir(char *);
void printlong(char *);
void print_size(struct stat *);
void print_date(struct stat *);
#endif
