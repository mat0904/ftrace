/*
** EPITECH PROJECT, 2023
** mat
** File description:
** prototype
*/

#pragma once
#define _GNU_SOURCE

#include <elf.h>
#include "../lib/queue/include/queue.h"
#include "include.h"
#include "syscall.h"
#include "signal.h"
#include "symbol.h"

#define NO_ENTRY(x) x->sh_size / x->sh_entsize

typedef struct {
    char *name;
    char format[1024];
    unsigned long int address;
} function_t;

typedef struct {
    pid_t pid;
    file_t *file;
    const char *path;
    struct user_regs_struct regs;
    queue_t *queue;
    Elf64_Shdr *strtab;
    Elf64_Shdr *symtab;
} ftrace_t;

typedef struct {
    enum {
        INVALID,
        FUNCTION,
        RETURN,
        SYSCALL
    } type;
    uint8_t opcode;
} opcode_t;

char **split(const char *string, const char *delim);
void free_n(int no_arg, ...);
int ftrace(const int ac, const char **av);
int execute_child(ftrace_t *trace);
void display_syscall(struct user_regs_struct *regs, pid_t pid, char **buf);
void display_syscall_ret(pid_t pid, char **buf_addr);
unsigned long to_big_endian(unsigned long opcode, size_t size);
_Bool do_function(ftrace_t *tracer, opcode_t *opcode);
_Bool is_function(void *file, struct user_regs_struct *regs, pid_t pid);

opcode_t get_opcode_type(ftrace_t *tracer);
char *resolve_lib(ftrace_t *tracer, unsigned long int address);

Elf64_Addr get_function_addr(ftrace_t *tracer, uint8_t);
