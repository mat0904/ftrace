/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** syscall.h
*/

#pragma once

#define SYSCALL_NOT_IMPLEMENTED -1

typedef struct syscall {
    int code;
    char name[64];
    int n_args;
} syscall_t;

extern const syscall_t syscalls[];
