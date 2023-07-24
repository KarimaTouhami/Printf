#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
    // ... existing code ...

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);
    for (p = (char *)format; *p; p++)
    {
        // ... existing code ...
        if (*p != '%')
        {
            sum += _putchar(*p);
            continue;
        }
        start = p;
        p++;
        while (get_flag(p, &params)) /* while char at p is flag char */
        {
            p++; /* next char */
        }
        p = get_width(p, &params, ap);
        p = get_precision(p, &params, ap);
        if (get_modifier(p, &params))
            p++;
        if (!get_specifier(p))
            sum += print_from_to(start, p,
                                 params.l_modifier || params.h_modifier ? p - 1 : 0);
        else
            sum += get_print_func(p, ap, &params);
    }

    // ... existing code ...

    return (sum);
}
