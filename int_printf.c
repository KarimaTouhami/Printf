#include "main.h"

/**
 * printf_int -> function that produces output according to a format
 * @handle: liste
 * owned by karkazou & S0UMIM00N
 * Return: counter of char
 */

int printf_int(va_list handle)
{
	int n = va_arg(handle, int);
	int count = 0, rev[11], i = 0;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (n != 0)
		{
			rev[i] = n % 10;
			n = n / 10;
			i++;
		}
		i--;
		while (i >= 0)
		{
			_putchar('0' + rev[i]);
			count++;
			i--;
		}
	}

	return (count);
}
