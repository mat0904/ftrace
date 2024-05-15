/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** get_section_name.c
*/

#include "ftrace.h"

char *get_section_name(file_t *file, Elf64_Shdr *section)
{
    Elf64_Shdr *strtab = (Elf64_Shdr *)&file->buffer[file->hdr->e_shoff +
        file->hdr->e_shstrndx * sizeof(Elf64_Shdr)];
    long long int offset = strtab->sh_offset + section->sh_name;
    char *name = &file->buffer[offset];

    return name;
}
