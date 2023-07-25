#include "main.h"

 /**
 * _printf - function that produces output according to a format
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @format: character string
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    int result = 0;
    va_list args;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    result += printf_char(args);
                    break;

                case 's':
                    result += printf_string(args);
                    break;

                case '%':
                    _putchar('%');
                    result++;
                    break;

                default:
                    _putchar('%');
                    _putchar(*format);
                    result += 2;
                    break;
            }
        }
        else
        {
            _putchar(*format);
            result++;
        }

        format++;
    }

    va_end(args);
    return result;
}

int printf_char(va_list args)
{
    char c = va_arg(args, int);
    return _putchar(c);
}

int printf_string(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;

    if (str == NULL)
        str = "(null)";

    while (str[len])
    {
        _putchar(str[len]);
        len++;
    }

    return len;
}
