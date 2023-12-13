#include "main.h"


/**
 * print_prompt - Simply the new thing is that it uses the custom printf.
 *
 * Return: Void
 */
void print_prompt(void)
{
	pid_t id = getpid();
	_printf(">> %d: ", id);
}
