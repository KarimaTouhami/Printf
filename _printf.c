#include "main.h"

/**
 * _printf - function that produces output according to a format
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @format: character string
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int total_chars_printed = 0; // Changed variable name from 'result' to 'total_chars_printed'
    va_list handle;

    va_start(handle, format);
    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            total_chars_printed += switch_char(handle, *format); // Updated variable name here
        }
        else
        {
            _putchar(*format);
            total_chars_printed++; // Updated variable name here
        }
        format++;
    }
    va_end(handle);
    return total_chars_printed; // Updated return statement here
}
