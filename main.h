#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>

#define OUTPUT_SIZE 1024

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list handle); // Prototype for the function used in switch_char
int printf_string(va_list handle); // Prototype for the function used in switch_char
int switch_char(va_list handle, char cara); // Prototype for the helper function in _printf
int printf_int(va_list handle); // Prototype for the function used in switch_char

#endif
