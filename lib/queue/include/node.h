/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** node.h
*/

#pragma once

#include <stdlib.h>
#include <sys/queue.h>

typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;
