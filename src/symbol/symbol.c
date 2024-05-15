/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** symbol.c
*/

#include "symbol.h"
#include "file.h"
#include "ftrace.h"
#include <elf.h>

static symbol_t *create_symbol(file_t *file, Elf64_Shdr *str_section,
    Elf64_Sym *symbol_ptr)
{
    symbol_t *symbol = malloc(sizeof(symbol_t));

    if (symbol == NULL) {
        return NULL;
    }
    symbol->addr = symbol_ptr;
    symbol->name = &file->buffer[str_section->sh_offset +
        symbol_ptr->st_name];
    return symbol;
}

static void fill_symbol_array(file_t *file, symbol_t **symbols,
    Elf64_Shdr *sym_section, Elf64_Shdr *str_section)
{
    unsigned int i = 0;
    unsigned int index = 0;
    unsigned int no_entry = sym_section->sh_size / sym_section->sh_entsize;
    Elf64_Sym *symbol_ptr = (Elf64_Sym *)&file->buffer[sym_section->sh_offset];
    symbol_t *symbol = NULL;

    while (index < no_entry) {
        if (symbol_ptr->st_name == 0) {
            symbol_ptr = &symbol_ptr[1];
            index += 1;
            continue;
        }
        symbol = create_symbol(file, str_section, symbol_ptr);
        if (symbol != NULL) {
            symbols[i] = symbol;
            i += 1;
        }
        index += 1;
        symbol_ptr = &symbol_ptr[1];
    }
}

static symbol_t **fetch_symbols_array(file_t *file, Elf64_Shdr *sym_section,
    Elf64_Shdr *str_section)
{
    unsigned int no_entry = sym_section->sh_size / sym_section->sh_entsize;
    symbol_t **symbols = malloc(sizeof(symbol_t *) * (no_entry + 1));

    if (symbols == NULL) {
        return NULL;
    }
    memset(symbols, 0, sizeof(symbol_t *) * (no_entry + 1));
    fill_symbol_array(file, symbols, sym_section, str_section);
    return symbols;
}

symbol_t **fetch_symbols(file_t *file)
{
    Elf64_Shdr *sym_sections = get_section_by_name(file, ".symtab");
    Elf64_Shdr *str_sections = get_section_by_name(file, ".strtab");
    symbol_t **symbols = NULL;

    if (sym_sections == NULL || str_sections == NULL) {
        return NULL;
    }
    symbols = fetch_symbols_array(file, sym_sections, str_sections);
    return symbols;
}
