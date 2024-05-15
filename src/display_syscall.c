/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** display_syscall.c
*/

#include "ftrace.h"
#include <sys/user.h>

static void display_arguments(struct user_regs_struct *regs, char **buf_addr)
{
    int i = 0;
    const syscall_t *syscall = &syscalls[regs->rax];
    unsigned long long int *registers_array[] = {&regs->rdi, &regs->rsi,
        &regs->rdx, &regs->rcx, &regs->r8, &regs->r9
    };

    while (i < syscall->n_args) {
        if (i > 0)
            *buf_addr += sprintf(*buf_addr, ", ");
        *buf_addr += sprintf(*buf_addr, "0x%llx", *registers_array[i]);
        i += 1;
    }
}

void display_syscall_ret(pid_t pid, char **buf_addr)
{
    long long int rax = ptrace(PTRACE_PEEKUSER, pid, 8 * RAX, NULL);

    if (rax == -1) {
        *buf_addr += sprintf(*buf_addr, "?");
    } else {
        *buf_addr += sprintf(*buf_addr, "0x%llx", rax);
    }
}

void display_syscall(struct user_regs_struct *regs, pid_t pid, char **buf_addr)
{
    *buf_addr += sprintf(*buf_addr, "Syscall %s(", syscalls[regs->rax].name);
    display_arguments(regs, buf_addr);
    *buf_addr += sprintf(*buf_addr, ") = ");
}
