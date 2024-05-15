/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** insert.c
*/

#include "../include/head.h"

void insert(struct head_s *head, void *data, int index)
{
    node_t *tmp_node = NULL;
    node_t *new_node = create_node(data);

    if (index == 0) {
        head->push_front(head, data);
    } else {
        tmp_node = get(head, index - 1);
        new_node->next = tmp_node->next;
        tmp_node->next = new_node;
    }
}
