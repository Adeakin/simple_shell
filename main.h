#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>


extern char **environ;


/* For _printf */
int _printf(const char *format, ...);
int _putchar(char c, int *counter_addr);
void str_handler(char *str, int *counter);
void print_digit(long num, char format, int *counter);
int dixX_check(char suspect, char *list);


/* For simple_shell */
void print_prompt();
char **read_and_tokenise();
char **tokenise_prompt(char *str, char *delimeter);
char **execute_prompt(char **argv);
char **tokenise_env_val(char *wanted_key);
char *pather(char **token_array, char *prompt_input);
void free_ptr2ptr(char **argv);


#endif
