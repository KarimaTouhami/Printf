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
				case 'i':
					int n = va_arg(args,int);
					int num, last = n%10, digit, exp =1;
					int i = 1;
					n = n/10;
					
					// if n is n= 5673, num would be n/10 
					// last = n % 10
					// since num =  n/10 = 567.[3] <- last
					num = n;
					
					if (last < 0)
					{
						putchar('-');
						num = -num;
						n = -n;
						last = -last;
						count++;
					}
					if (num > 0)
					{
						while (num /10 != 0)
						{
							exp = exp * 10;
							num = num / 10;
						}
						num = n;

						while (exp > 0) 
						{
							digit = num / exp;
							putchar(digit + '0');
							exp = exp / 10;
							count++;
						}	
					}
					putchar(last + '0');
					count++;
					break;
				case 'd':
					int n = va_arg(args, int);
					int num, last = n%10,digit;
					int i = 1, exp = 1;

					n = n/10;
					num = n;
					//handling negative sign
					if (last < 0)
					{
						putchar('-');
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
							putchar(digit + '0');
							num = num - (digit * exp);
							exp = exp / 10;
							count++;
						}
					}
					putchar(last + '0');
					count++;
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
