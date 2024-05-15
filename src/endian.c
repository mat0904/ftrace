/*
** EPITECH PROJECT, 2024
** ftrace
** File description:
** -> Endianness
*/

#include "ftrace.h"
#include <limits.h>

static _Bool is_big_endian(void)
{
    uint16_t word = 0xFF00;

    return ((uint8_t *)&word)[0] == 0xFF;
}

static unsigned long make_mask(size_t size)
{
    unsigned long mask = 0;

    for (; size; size--) {
        mask = (mask << 8) | 0xFF;
    }
    return mask;
}

unsigned long to_big_endian(unsigned long opcode, size_t size)
{
    unsigned long n = 0;

    if (!is_big_endian()) {
        for (; size; size--) {
            n = (n << 8) | (opcode & 0xFF);
            opcode >>= 8;
        }
        return n;
    } else {
        return opcode & make_mask(size);
    }
}
