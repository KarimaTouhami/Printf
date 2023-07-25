#include "main.h"

/**
 * printf_int -> function that produces output according to a format
 * @handle: liste
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

/**
 * printf_dec - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */

int printf_dec(va_list handle)
{
	int n = va_arg(args, int);
	int num, last = n%10,digit;
	int count = 1, exp = 1;

	n = n/10;
	num = n;
	
	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		count++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
			
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			count++;
		}
	}
	_putchar(last + '0');
	count++;
	
	return (count);
}

