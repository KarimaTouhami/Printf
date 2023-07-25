#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @d: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char d)
{
	return (write(1, &d, 1));
}

/**
 * printf_char - Entry point
 * @handle: inpute
 * Return: Always 0
 */

int printf_char(va_list handle)
{
	char d;

	d = va_arg(handle, int);

	_putchar(d);

	return (1);
}

/**
 * printf_string - Entry point
 * @handle: inpute
 * Return: Always 0
 */

int printf_string(va_list handle)
{
	char *f;
	int i = 0;

	f = va_arg(handle, char *);

	if (f == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (*f)
		{
			_putchar(*f);
			i++;
			f++;
		}
	}
	return (i);
}
