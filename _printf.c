#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	if (format == NULL) return -1;
	va_list args;
	va_start(args, format);
	int count = 0;
	char specifier;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == NULL) break;
			switch (*format)
			{
				case '%': putchar('%'); count++; break;
				case 'c': specifier = va_arg(args, int); putchar(specifier); count++; break;
				case 's':
					{ char *str = va_arg(args, char *); if (str == NULL) str = "(null)";
						while (*str) { putchar(*str); str++; count++; } break; }
				default: putchar('%'); putchar(*format); count += 2; break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
