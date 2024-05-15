/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** signal.c
*/

#include "ftrace.h"

bool detect_signal(pid_t child, int status, bool *is_running)
{
    int signum = 0;

    if (WIFSIGNALED(status)) {
        signum = WTERMSIG(status);
        fprintf(stderr, "+++ killed by %s +++\n", signals[signum - 1]);
        *is_running = false;
        return true;
    }
    if (WIFSTOPPED(status)) {
        signum = WSTOPSIG(status);
        if (signum != 5) {
            fprintf(stderr, "Received signal %s\n", signals[signum - 1]);
            ptrace(PTRACE_CONT, child, NULL, signum);
        }
        return false;
    }
    return false;
}
