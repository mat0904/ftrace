/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** head.h
*/

#pragma once

#include "node.h"
#include <stdlib.h>
#include <string.h>
#include "queue.h"

node_t *create_node(void *data);

node_t *get(head_t *head, int index);

void push_front(head_t *head, void *data);
void push_back(head_t *head, void *data);
void *front(head_t *head);
void *back(head_t *head);
void *at_queue(head_t *head, int index);
void insert(head_t *head, void *data, int index);
unsigned int size(head_t *head);
void foreach(head_t *head, void (*func)(void *arg));
void foreach_arg(head_t *head, void (*func)(void *arg, va_list list), ...);
bool in_queue(struct head_s *head, void *cmp);
void remove_node(struct head_s *head, unsigned int index);
