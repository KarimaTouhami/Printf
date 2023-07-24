#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int test = 0;
    test = _printf("test char %d\n", 0);
    printf("%d\n", test);
    test = _printf("test char %d\n", 12);
    printf("%d\n", test);
    test = _printf("test char %d\n", 34535354);
    printf("%d\n", test);
    test = _printf("test char %d\n", -34535354);
    printf("%d\n", test);
    test = _printf("test char %d\n", 2147483647);
    printf("%d\n", test);
    return (0);
}
