#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @counter_addr: points to the addres of the count of printed chars
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int *counter_addr)
{
	(*counter_addr) += 1;
	return (write(1, &c, 1));
}
