/*
** EPITECH PROJECT, 2024
** ftrace
** File description:
** -> Function
*/

#include "utils.h"
#include "ftrace.h"
#include <string.h>

static _Bool call_function
(ftrace_t *tracer, char *name, Elf64_Addr addr, Elf64_Sym *sym)
{
    char *lib = NULL;
    function_t *function = malloc(sizeof(function_t));

    if (!function)
        return false;
    memset(function, 0, sizeof(function_t));
    function->name = name;
    function->address = addr;
    tracer->queue->push_back(tracer->queue, function);
    if (name != NULL && sym != NULL && sym->st_name != 0) {
        sprintf(function->format, "%s", name);
    } else {
        lib = resolve_lib(tracer, addr);
        sprintf(function->format, "func_0x%lx@%s", addr, lib);
        free(lib);
    }
    fprintf(stderr, "Entering function %s at 0x%lx\n", function->format, addr);
    return true;
}

static _Bool ret_function(ftrace_t *tracer)
{
    unsigned int size = tracer->queue->size(tracer->queue);
    static const char *const fmt = "Leaving function %s\n";
    function_t *function = tracer->queue->at(tracer->queue, size - 1);

    if (size == 0)
        return false;
    fprintf(stderr, fmt, function->format);
    free(tracer->queue->back(tracer->queue));
    tracer->queue->remove(tracer->queue, size - 1);
    return true;
}

static void fetch_symbol(ftrace_t *tracer, unsigned long int func_addr)
{
    Elf64_Sym *sym = (tracer->symtab == NULL) ? NULL :
        (Elf64_Sym *)(tracer->file->buffer + tracer->symtab->sh_offset);
    Elf64_Shdr *symtab = tracer->symtab;
    Elf64_Shdr *strtab = tracer->strtab;

    if (tracer->symtab == NULL || tracer->strtab == NULL) {
        call_function(tracer, NULL, tracer->regs.rip, NULL);
        return;
    }
    for (uint8_t i = 0; i < symtab->sh_size / symtab->sh_entsize; i += 1) {
        if (sym->st_value == func_addr) {
            call_function(tracer, &tracer->file->buffer[strtab->sh_offset +
                sym->st_name], tracer->regs.rip, sym);
            return;
        }
        sym++;
    }
    call_function(tracer, NULL, tracer->regs.rip, sym);
}

_Bool do_function(ftrace_t *tracer, opcode_t *opcode)
{
    unsigned long func_addr = 0;

    if (opcode->type == RETURN) {
        ret_function(tracer);
        return true;
    }
    func_addr = get_function_addr(tracer, opcode->opcode);
    get_regs(tracer);
    fetch_symbol(tracer, func_addr);
    return true;
}
