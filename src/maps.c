/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** maps.c
*/

#include "ftrace.h"
#include <errno.h>

static char *is_in_range_binding(char *line, unsigned long int address)
{
    unsigned long int start = 0;
    unsigned long int end = 0;

    sscanf(line, "%lx-%lx", &start, &end);
    if (address >= start && address <= end) {
        return strndup(&line[73], strlen(&line[73]) - 1);
    }
    return NULL;
}

static char *resolve_lib_entry(ftrace_t *tracer, FILE *file,
    unsigned long int address)
{
    char *lib = NULL;
    char *line = NULL;
    size_t len = 0;
    int read_size = 0;

    read_size = getline(&line, &len, file);
    while (read_size != -1) {
        lib = is_in_range_binding(line, address);
        if (lib != NULL) {
            free(line);
            return lib;
        }
        read_size = getline(&line, &len, file);
    }
    free(line);
    return NULL;
}

char *resolve_lib(ftrace_t *tracer, unsigned long int address)
{
    char *line = NULL;
    FILE *file = NULL;
    char path[1024] = {0};

    snprintf(path, 1024, "/proc/%d/maps", tracer->pid);
    file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }
    line = resolve_lib_entry(tracer, file, address);
    fclose(file);
    return line;
}
