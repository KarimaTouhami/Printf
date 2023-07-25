#include "main.h"

/**
 * _printf - function that produces output according to a format
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @format: character string
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int num_chars_printed = 0; // Changed variable name to num_chars_printed
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
            num_chars_printed += switch_char(args, *format); // Updated variable name here
        }
        else
        {
            _putchar(*format);
            num_chars_printed++; // Updated variable name here
        }
        format++;
    }
    va_end(args);
    return (num_chars_printed); // Updated variable name here
}
