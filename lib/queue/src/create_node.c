/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_node.c
*/

#include "../include/node.h"

node_t *create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}
