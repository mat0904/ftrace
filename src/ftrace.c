/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** ftrace.c
*/

#include "ftrace.h"
#include "file.h"
#include "symbol.h"

static void find_sections(file_t *file, Elf64_Shdr **strtab,
    Elf64_Shdr **symtab)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)&file->buffer[file->hdr->e_shoff];
    unsigned int long offset = sections[file->hdr->e_shstrndx].sh_offset;
    char *shstrtab = &file->buffer[offset];

    for (size_t i = 0; i < file->hdr->e_shnum; i += 1) {
        if (strcmp(shstrtab + sections[i].sh_name, ".strtab") == 0) {
            *strtab = (Elf64_Shdr *)&sections[i];
        }
        if (strcmp(shstrtab + sections[i].sh_name, ".symtab") == 0) {
            *symtab = (Elf64_Shdr *)&sections[i];
        }
    }
}

static int init_ftrace(ftrace_t *tracer, const char *path)
{
    memset(tracer, 0, sizeof(ftrace_t));
    tracer->file = open_file(path);
    if (tracer->file == NULL) {
        return 84;
    }
    tracer->queue = create_queue();
    if (tracer->queue == NULL) {
        close_file(tracer->file);
        return 84;
    }
    tracer->path = path;
    find_sections(tracer->file, &tracer->strtab, &tracer->symtab);
    return 0;
}

int ftrace(const int ac, const char **av)
{
    const char *path = av[1];
    ftrace_t tracer;

    if (init_ftrace(&tracer, path) == 84) {
        return 84;
    }
    execute_child(&tracer);
    close_file(tracer.file);
    tracer.queue->foreach(tracer.queue, &free);
    delete_queue(tracer.queue);
    return 0;
}
