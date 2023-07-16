#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format.
 * @format: format string containing the characters and the specifiers.
 *
 * Description: This function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	char specifier;

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			if (*format == '\0')
				break;

			switch (*format)
			{
				case '%':
					putchar('%');
					count++;
					break;
				case 'c':
					specifier = va_arg(args, int);
					putchar(specifier);
					count++;
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str)
						{
							putchar(*str);
							str++;
							count++;
						}
					}
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++; /* Move to the next character in the format string */
	}

	va_end(args);
	return count;
}
