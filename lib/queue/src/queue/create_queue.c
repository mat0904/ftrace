/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** create_queue.c
*/

#include "../../include/queue.h"
#include "../../include/head.h"

queue_t *create_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));

    if (queue == NULL) {
        return NULL;
    }
    memset(queue, 0, sizeof(queue_t));
    queue->push_front = &push_front;
    queue->push_back = &push_back;
    queue->front = &front;
    queue->back = &back;
    queue->at = &at_queue;
    queue->insert = &insert;
    queue->size = &size;
    queue->foreach = &foreach;
    queue->foreach_arg = &foreach_arg;
    queue->contains = &in_queue;
    queue->remove = &remove_node;
    return queue;
}
