/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** foreach.c
*/

#include "../include/head.h"

void foreach_arg(head_t *head, void (*func)(void *arg, va_list list), ...)
{
    unsigned int i = 0;
    va_list list;

    while (i < head->size(head)) {
        va_start(list, func);
        func(head->at(head, i), list);
        va_end(list);
        i += 1;
    }
}

void foreach(head_t *head, void (*func)(void *arg))
{
    unsigned int i = 0;

    while (i < head->size(head)) {
        func(head->at(head, i));
        i += 1;
    }
}
