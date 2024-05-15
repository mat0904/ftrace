/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** remove.c
*/

#include "../include/queue.h"
#include "../include/node.h"
#include "../include/head.h"
#include <stdio.h>

void remove_node(struct head_s *head, unsigned int index)
{
    node_t *tmp_node = NULL;
    node_t *node = get(head, index - 1);

    if (head == NULL || head->head == NULL) {
        return;
    }
    if (index == 0) {
        tmp_node = head->head;
        head->head = head->head->next;
        free(tmp_node);
    } else {
        if (node == NULL || node->next == NULL) {
            return;
        }
        tmp_node = node->next;
        node->next = node->next->next;
        free(tmp_node);
    }
}
