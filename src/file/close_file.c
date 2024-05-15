/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** close_file.c
*/

#include "file.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

void close_file(file_t *file)
{
    if (file == NULL) {
        return;
    }
    if (file->fd != -1) {
        close(file->fd);
    }
    munmap(file->buffer, file->stat.st_size);
    delete_file(file);
}
