#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int result = 0;
    va_list args;

    va_start(args, format);
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            result += switch_char(args, *format);
        }
        else
        {
            _putchar(*format);
            result++;
        }
        format++;
    }
    va_end(args);
    return (result);
}
