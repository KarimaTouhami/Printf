#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int chars_printed = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past the '%'
            char specifier = *format;

            if (specifier == '\0') {
                // Handle the case when '%' is at the end of the format string
                break;
            }
            else if (specifier == 'c') {
                // Character specifier
                char c = (char)va_arg(args, int);
                putchar(c);
                chars_printed++;
            }
            else if (specifier == 's') {
                // String specifier
                char *str = va_arg(args, char*);
                while (*str) {
                    putchar(*str);
                    str++;
                    chars_printed++;
                }
            }
            else if (specifier == '%') {
                // Print a literal '%'
                putchar('%');
                chars_printed++;
            }
            else {
                // Unrecognized specifier, skip it
                putchar('%');
                putchar(specifier);
                chars_printed += 2;
            }
        }
        else {
            // Regular character, just print it
            putchar(*format);
            chars_printed++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);
    return chars_printed;
}

int main() {
    int chars_printed = _printf("Hello, %s! This is a test. The character is %c and the percentage is %%.\n", "Alice", 'X');
    printf("\nTotal characters printed (excluding the null byte): %d\n", chars_printed);
    return 0;
}
