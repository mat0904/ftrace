/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** symbol.h
*/

#pragma once

#include "file.h"
#include <sys/stat.h>
#include <libelf.h>
#include <sys/mman.h>

typedef struct symbol_s {
    char *name;
    Elf64_Sym *addr;
} symbol_t;

symbol_t **fetch_symbols(file_t *file);

char *get_section_name(file_t *file, Elf64_Shdr *section);
Elf64_Shdr **get_section_by_type(file_t *file, Elf64_Word type);
Elf64_Shdr *get_section_by_name(file_t *file, char *name);
