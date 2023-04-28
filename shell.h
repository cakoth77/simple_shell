#ifndef MAIN_H
#define MAIN_H
#define TMAX 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
int main(int ac, char **av);
int _isalpha(int c);
int string_to_int(char *str);

#endif
