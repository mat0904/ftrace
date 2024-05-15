/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** delete_file.c
*/

#include "file.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

void delete_file(file_t *file)
{
    if (file == NULL) {
        return;
    }
    free(file);
}
