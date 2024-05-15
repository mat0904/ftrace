/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** create_file.c
*/

#include "file.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

file_t *open_file(const char *path)
{
    file_t *file = create_file();

    if (file == NULL) {
        return NULL;
    }
    file->fd = open(path, O_RDONLY);
    if (file->fd == -1) {
        delete_file(file);
        return NULL;
    }
    fstat(file->fd, &file->stat);
    file->buffer = mmap(NULL, file->stat.st_size, PROT_READ, MAP_PRIVATE,
        file->fd, 0);
    return file;
}
