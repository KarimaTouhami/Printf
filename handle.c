#include "main.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printf_char - Entry point
 * @handle: inpute
 * Return: Always 0
 */

int printf_char(va_list handle)
{
	char c;

	c = va_arg(handle, int);

	_putchar(c);

	return (1);
}

/**
 * printf_string - Entry point
 * @handle: inpute
 * Return: Always 0
 */

int printf_string(va_list handle)
{
	char *s;
	int i = 0;

	s = va_arg(handle, char *);

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (*s)
		{
			_putchar(*s);
			i++;
			s++;
		}
	}
	return (i);
}
