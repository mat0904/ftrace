/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** utils.h
*/

#pragma once

#include <elf.h>
#include <stdlib.h>
#include <ftrace.h>
#include <sys/ptrace.h>

static inline Elf64_Ehdr *get_elf_header(void *file)
{
    return (Elf64_Ehdr *)file;
}

static inline _Bool is_64_bits_elf(void *file)
{
    return ((Elf32_Ehdr *)file)->e_ident[EI_CLASS] == ELFCLASS64;
}

static inline Elf64_Shdr *get_first_section_header(void *file)
{
    return (Elf64_Shdr *)((char *)file + get_elf_header(file)->e_shoff);
}

static inline void get_regs(ftrace_t *tracer)
{
    ptrace(PTRACE_GETREGS, tracer->pid, NULL, &tracer->regs);
}

static inline void go_forward(ftrace_t *tracer, int *status)
{
    ptrace(PTRACE_SINGLESTEP, tracer->pid, NULL, NULL);
    waitpid(tracer->pid, status, 0);
    get_regs(tracer);
}
