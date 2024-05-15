/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** is_working.c
*/

#include "tests.h"

Test(is_working, is_working, .init = redirect_all_std) {
    cr_assert_str_eq("is working", "is working");
}
