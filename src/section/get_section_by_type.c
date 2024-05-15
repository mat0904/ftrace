/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** get_section
*/

#include "ftrace.h"

static unsigned int get_no_section_by_type(file_t *file, Elf64_Word type)
{
    unsigned int i = 0;
    unsigned int count = 0;
    Elf64_Shdr *shdr = (Elf64_Shdr *)&file->buffer[file->hdr->e_shoff];

    while (i < file->hdr->e_shnum) {
        if (shdr->sh_type == type) {
            count += 1;
        }
        shdr = &shdr[1];
        i += 1;
    }
    return count;
}

Elf64_Shdr **get_sections_by_type(file_t *file, Elf64_Word type)
{
    unsigned int i = 0;
    unsigned int index = 0;
    unsigned int count = get_no_section_by_type(file, type);
    Elf64_Shdr *shdr = (Elf64_Shdr *)&file->buffer[file->hdr->e_shoff];
    Elf64_Shdr **array = malloc(sizeof(Elf64_Shdr *) * (count + 1));

    if (array == NULL)
        return NULL;
    while (i < file->hdr->e_shnum) {
        if (shdr->sh_type == type) {
            array[index] = shdr;
            array[index + 1] = NULL;
            index += 1;
        }
        shdr = &shdr[1];
        i += 1;
    }
    return array;
}
