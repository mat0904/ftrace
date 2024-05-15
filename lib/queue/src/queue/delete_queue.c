/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** delete_queue.c
*/

#include "../../include/queue.h"
#include "../../include/node.h"

static void delete_node(node_t *node)
{
    if (node == NULL) {
        return;
    }
    delete_node(node->next);
    free(node);
}

void delete_queue(queue_t *queue)
{
    if (queue == NULL) {
        return;
    }
    delete_node(queue->head);
    free(queue);
}
