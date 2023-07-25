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
int printf_char(va_list args); // Updated function name
int printf_string(va_list args); // Updated function name
int switch_char(va_list args, char cara); // Updated function name
int printf_int(va_list args); // Updated function name

#endif
