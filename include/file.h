/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** file.h
*/

#pragma once

#include <elf.h>
#include <sys/stat.h>

typedef struct file_s {
    int fd;
    struct stat stat;
    union {
        char *buffer;
        Elf64_Ehdr *hdr;
    };
} file_t;

file_t *create_file(void);
void delete_file(file_t *file);
file_t *open_file(const char *path);
void close_file(file_t *file);
