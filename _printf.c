#include "main.h"

/**
 * _printf - Function that produces output according to a format.
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @format: Format string containing the specifiers.
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings).
 */

int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", printf_string},
		{"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int},
		{"%d", printf_dec},
		{"%b", printf_bin}, // Assuming you have implemented this function.
		{"%u", printf_unsigned},
		{"%o", printf_oct},
		{"%x", printf_hex},
		{"%X", printf_HEX},
		{"%S", printf_exclusive_string},
		{"%p", printf_pointer}
	};

	va_list args;
	int i, j, len = 0;
	int num_convert_match = sizeof(m) / sizeof(m[0]);

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		va_end(args);
		return (-1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < num_convert_match; j++)
			{
				if (m[j].id[0] == '%' && m[j].id[1] == format[i + 1])
				{
					len += m[j].f(args);
					i++;
					break;
				}
			}
			if (j == num_convert_match)
			{
				_putchar('%');
				len++;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(args);
	return (len);
}
