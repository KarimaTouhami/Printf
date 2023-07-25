#include "main.h"

/**
 * switch_char - helper function that handles format specifiers
 * @handle: va_list for variable arguments
 * @specifier: the format specifier character
 * Return: number of characters printed
 */
int switch_char(va_list handle, char specifier)
{
	int result = 0;

	switch (specifier)
	{
	case 'c':
		_putchar(va_arg(handle, int));
		result++;
		break;
	case 's':
		result += switch_string(handle);
		break;
	case 'd':
	case 'i':
		result += switch_integer(handle);
		break;
	default:
		_putchar('%');
		_putchar(specifier);
		result += 2;
		break;
	}

	return result;
}

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: counter of char
 */
int _printf(const char *format, ...)
{
	int result = 0;
	va_list handle;

	va_start(handle, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		va_end(handle);
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		va_end(handle);
		return (-1);
	}

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			result += switch_char(handle, *format);
		}
		else
		{
			_putchar(*format);
			result++;
		}
		format++;
	}

	va_end(handle);
	return (result);
}
