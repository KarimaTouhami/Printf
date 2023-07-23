#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Produces output according to a format.
 * @format: Character string.
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);
	va_list args;
	va_start(args, format);
	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				putchar(va_arg(args, int)), count++;
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
					putchar(*str++), count++;
			}
			else
				putchar('%'), putchar(*format), count += 2;
		}
		else
			putchar(*format), count++;
		format++;
	}
	va_end(args);
	return (count);
}
