/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** push_back.c
*/

#include "../include/head.h"
#include <stdio.h>

void push_back(head_t *head, void *data)
{
    node_t *node = NULL;
    node_t *last_node = NULL;
    int index = head->size(head) - 1;

    if (head == NULL) {
        return;
    }
    node = create_node(data);
    if (node == NULL) {
        return;
    }
    if (index < 0) {
        head->head = node;
    } else {
        last_node = get(head, index);
        last_node->next = node;
    }
}
