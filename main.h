#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


/* For _printf */
int _printf(const char *format, ...);
int _putchar(char c, int *counter_addr);
void str_handler(char *str, int *counter);
void print_digit(long num, char format, int *counter);
int dixX_check(char suspect, char *list);


int betty(void);
char **tokenisation(*line, *delimeter);

#endif
