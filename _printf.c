#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - function that produces output according to a format
 * AUTHORS: TouhamiKarima & Ayoub Elmohamedi
 * @format: identifier
 * Return: string length
 */

int _printf(const char *format, ...)
{
    convert_match m[] = {
        {"%s", printf_string, 0}, {"%c", printf_char, 0},
        {"%%", printf_37, 0}, {"%i", printf_int, -1},
        {"%d", printf_dec, -1}, {"%b", printf_bin, 0},
        {"%u", printf_unsigned, -1}, {"%o", printf_oct, 0},
        {"%x", printf_hex, 0}, {"%X", printf_HEX, 0},
        {"%S", printf_exclusive_string, 0}, {"%p", printf_pointer, 0},
        {"%r", printf_srev, 0}, {"%R", printf_rot13, 0}
    };

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

Here:
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '.')
            {
                // Precision is specified for the current conversion specifier
                i++; // Move past the '.' character
                int precision = 0;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    precision = precision * 10 + (format[i] - '0');
                    i++;
                }
                m[j].precision = precision;
            }
            else
            {
                m[j].precision = -1; // Reset precision for the current conversion specifier
            }

            j = 13;
            while (j >= 0)
            {
                if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
                {
                    len += m[j].f(args);
                    i = i + 2;
                    goto Here;
                }
                j--;
            }
        }
        _putchar(format[i]);
        len++;
        i++;
    }
    va_end(args);
    return (len);
}
