/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** at.c
*/

#include "../include/head.h"

void *at_queue(head_t *head, int index)
{
    node_t *tmp_node = get(head, index);

    if (tmp_node == NULL) {
        return NULL;
    } else {
        return tmp_node->data;
    }
}
