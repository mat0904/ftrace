/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** free.c
*/

#include <stdarg.h>
#include <stdlib.h>

void free_n(int no_arg, ...)
{
    int i = 0;
    va_list list;
    void *ptr = NULL;

    va_start(list, no_arg);
    while (i < no_arg) {
        ptr = va_arg(list, void *);
        free(ptr);
        i += 1;
    }
    va_end(list);
}
