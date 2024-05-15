/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** create_file.c
*/

#include "file.h"
#include <stdlib.h>
#include <string.h>

file_t *create_file(void)
{
    file_t *file = malloc(sizeof(file_t));

    if (file == NULL) {
        return NULL;
    }
    memset(file, 0, sizeof(file_t));
    file->fd = -1;
    return file;
}
