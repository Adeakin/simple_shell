#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/**
 * _printf - produces output according to a format
 * @format: a string that contains the format to print
 * Return: output to stdout, the standard output stream
*/

int _printf(const char *format, ...)
{
	int i = 0, *counter = malloc(sizeof(int)), counter_helper;
	va_list args;

	if (format == NULL || format[1] == '\0' || counter == NULL)
		return (-1);
	*counter = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[++i])
		{
			if (format[i] == 's')
				str_handler(va_arg(args, char *), counter);
			else if (format[i] == 'c')
				_putchar(va_arg(args, int), counter);
			else if (dixX_check(format[i], "di"))
				print_digit((long)(va_arg(args, int)), format[i], counter);
			else if (dixX_check(format[i], "xX"))
				print_digit((long)(va_arg(args, unsigned int)), format[i], counter);
			else if (format[i] == '%')
				_putchar(format[i], counter);
			else
				_putchar('%', counter), _putchar(format[i], counter);
		}
		else
		{
			_putchar(format[i], counter);
		}
		i++;
	}

	va_end(args);
	counter_helper = *counter;
	free(counter);
	return (counter_helper);
}


/**
 * dixX_check - checks if the given character is one of these "dixX"
 * @suspect: the character to be checked
 * @list: the list to check from
 * Return: int, returns a truthy value if the character is in the list
*/

int dixX_check(char suspect, char *list)
{
	int i = 0;

	while (list[i] != '\0')
	{
		if (list[i] == suspect)
			return (1);
		i++;
	}
	return (0);
}


/**
 * str_handler - triggers the _putchar until the whole passed string is done
 * @str: the pointer to the string to be printed
 * @counter: the address of where the counter is stolen
 * Return: void
*/

void str_handler(char *str, int *counter)
{
	int str_indexer = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return;
	}
	while (str[str_indexer] != '\0')
	{
		_putchar(str[str_indexer], counter);
		str_indexer++;
	}
}


/**
 * print_digit - Solve the printing of dec or hex according to the base argument
 * @num: The number to be parsed
 * @format: The format to consider when parsing the num
 * @counter: The pointer to the counter address
 *
 * Return: void
*/

void print_digit(long num, char format, int *counter)
{
	char *symbols = "0123456789abcdef";
	int base;

	if (format == 'd' || format == 'i')
	{
		base = 10;
	}
	else if (format == 'x')
	{
		base = 16;
	}
	else if (format == 'X')
	{
		base = 16;
		symbols = "0123456789ABCDEF";
	}

	if (num < 0)
	{
		_putchar('-', counter);
		print_digit(-num, format, counter);
	}
	else if (num < base)
	{
		_putchar(symbols[num], counter);
	}
	else
	{
		long helper1 = num / base;
		long helper2 = num % base;

		print_digit(helper1, format, counter);
		print_digit(helper2, format, counter);
	}
}
