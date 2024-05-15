/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** opcode_type.c
*/

#include "ftrace.h"
#include "utils.h"

static opcode_t get_opcode_type_impl
(unsigned long opcode, struct user_regs_struct *regs, pid_t pid)
{
    const uint8_t _opcode = to_big_endian(opcode, 1);

    switch (_opcode) {
    case 0xE8:
    case 0x9A:
    case 0xE9:
    case 0xFF:
        return (opcode_t) { .type = FUNCTION, .opcode = _opcode };
    case 0xC2:
    case 0xC3:
    case 0xCA:
    case 0xCB:
        return (opcode_t) { .type = RETURN, .opcode = _opcode };
    }
    if (to_big_endian(opcode, 2) == 0x0f05) {
        return (opcode_t) { .type = SYSCALL, .opcode = 0 };
    }
    return (opcode_t) { .type = INVALID, .opcode = 0 };
}

opcode_t get_opcode_type(ftrace_t *tracer)
{
    long opcode;

    get_regs(tracer);
    opcode = ptrace(PTRACE_PEEKTEXT, tracer->pid, tracer->regs.rip);
    if (opcode == -1) {
        return (opcode_t) { .type = INVALID, .opcode = 0 };
    }
    return get_opcode_type_impl((unsigned long)opcode, &tracer->regs,
        tracer->pid);
}
