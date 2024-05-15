/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** get_section
*/

#include "ftrace.h"

Elf64_Shdr *get_section_by_name(file_t *file, char *name)
{
    unsigned int i = 0;
    unsigned int offset = 0;
    Elf64_Shdr *shdr = (Elf64_Shdr *)&file->buffer[file->hdr->e_shoff];
    Elf64_Shdr *strtab = (Elf64_Shdr *)&file->buffer[file->hdr->e_shoff +
        file->hdr->e_shstrndx * sizeof(Elf64_Shdr)];

    while (i < file->hdr->e_shnum) {
        offset = strtab->sh_offset + shdr->sh_name;
        printf("%s\n", &file->buffer[offset]);
        if (strcmp(&file->buffer[offset], name) == 0) {
            return shdr;
        }
        shdr = &shdr[1];
        i += 1;
    }
    return NULL;
}
