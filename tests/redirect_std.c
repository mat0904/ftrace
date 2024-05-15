/*
** EPITECH PROJECT, 2024
** base_repo
** File description:
** redirect_std.c
*/

#include "tests.h"

void redirect_all_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}
