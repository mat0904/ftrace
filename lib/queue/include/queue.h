/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** queue.h
*/

#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct head_s {
    struct node_s *head;
    void (*push_front)(struct head_s *head, void *data);
    void (*push_back)(struct head_s *head, void *data);
    void *(*front)(struct head_s *head);
    void *(*back)(struct head_s *head);
    void *(*at)(struct head_s *head, int index);
    void (*insert)(struct head_s *head, void *data, int index);
    void (*foreach)(struct head_s *head, void (*func)(void *arg));
    void (*foreach_arg)(struct head_s *head,
        void (*func)(void *, va_list list), ...);
    bool (*contains)(struct head_s *head, void *cmp);
    unsigned int (*size)(struct head_s *head);
    void (*remove)(struct head_s *head, unsigned int index);
} head_t;

typedef head_t queue_t;

queue_t *create_queue(void);
void delete_queue(queue_t *queue);
