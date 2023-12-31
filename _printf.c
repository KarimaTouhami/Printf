#include "main.h"

/**
 * _printf - function that produces output according to a format
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @format: identifier
 * Return: string length
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37}, {"%i", printf_int},
		{"%d", printf_dec}, {"%b", printf_bin},
		{"%u", printf_unsigned}, {"%o", printf_oct},
		{"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		j = 11;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				break;
			}
			j--;
		}
		if (j < 0)
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
