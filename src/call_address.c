/*
** EPITECH PROJECT, 2024
** ftrace
** File description:
** -> Function call address
*/

#include "utils.h"
#include "ftrace.h"

Elf64_Addr get_function_addr(ftrace_t *tracer, uint8_t opcode)
{
    int status = 0;
    char modrm = 0;

    if (opcode != 0xE8 && opcode != 0xFF && opcode != 0x9A)
        return 0;
    if (opcode == 0xFF) {
        modrm = ptrace(PTRACE_PEEKTEXT, tracer->pid, tracer->regs.rip + 1);
        modrm >>= 6;
        if (modrm != 0 && modrm != 1 && modrm != 2 && modrm != 3)
            return 0;
    }
    go_forward(tracer, &status);
    return tracer->regs.rip;
}
