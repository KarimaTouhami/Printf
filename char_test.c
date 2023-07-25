#include "main.h"

/**
 * switch_char -> function that produces output according to a format
 * @handle: list
 * @cara: character
 * Return: counter of char
 */

int switch_char(va_list handle, char cara)
{
	int print_c = 0;

	switch (cara)
	{
		case 'c':
			print_c += printf_char(handle);
			break;
		case 's':
			print_c += printf_string(handle);
			break;
		case 'd':
			print_c += printf_dec(handle);
			break;
		case 'i':
			print_c += printf_int(handle);
			break;
		case 'o':
			print_c += printf_oct(handle);
			break;
		case '%':
			_putchar('%');
			print_c++;
			break;
		default:
			_putchar('%');
			_putchar(cara);
			print_c += 2;
			break;
	}

	return (print_c);
}
