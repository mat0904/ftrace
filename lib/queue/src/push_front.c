/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** push_front.c
*/

#include "../include/head.h"

void push_front(head_t *head, void *data)
{
    node_t *node = create_node(data);

    if (node == NULL) {
        return;
    }
    node->next = head->head;
    head->head = node;
}
