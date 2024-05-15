/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** fork.c
*/

#include "utils.h"
#include "file.h"
#include "ftrace.h"
#include "signal.h"
#include "symbol.h"
#include <stdint.h>
#include <stdlib.h>
#include <sys/user.h>

static void exec_opcode(ftrace_t *tracer, int *status)
{
    char syscall_buf[256] = { 0 };
    char *write = syscall_buf;
    opcode_t opcode = get_opcode_type(tracer);

    if (opcode.type == FUNCTION || opcode.type == RETURN) {
        do_function(tracer, &opcode);
    } else if (opcode.type == SYSCALL) {
        display_syscall(&tracer->regs, tracer->pid, &write);
    }
    go_forward(tracer, status);
    if (opcode.type == SYSCALL) {
        display_syscall_ret(tracer->pid, &write);
        fprintf(stderr, "%s\n", syscall_buf);
    }
}

static int parent_process(ftrace_t *tracer)
{
    int status = 0;
    bool is_running = true;

    waitpid(tracer->pid, &status, 0);
    while (is_running && !WIFEXITED(status)) {
        if (detect_signal(tracer->pid, status, &is_running) == true)
            continue;
        exec_opcode(tracer, &status);
    }
    fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(status));
    return status;
}

int execute_child(ftrace_t *tracer)
{
    tracer->pid = fork();
    if (tracer->pid == -1)
        return 84;
    if (tracer->pid == 0) {
        ptrace(PTRACE_TRACEME, tracer, NULL, NULL);
        execve(tracer->path, (char *[]){ (char *)tracer->path, NULL }, NULL);
        perror("");
    } else {
        parent_process(tracer);
    }
    return 0;
}
