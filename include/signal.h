/*
** EPITECH PROJECT, 2024
** B-PSU-400-LYN-4-1-ftrace-thomas.sayen
** File description:
** signal.h
*/

#pragma once

#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>

extern const char *signals[32];
bool detect_signal(pid_t child, int status, bool *is_running);
