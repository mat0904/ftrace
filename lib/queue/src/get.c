/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** get.c
*/

#include "../include/head.h"

node_t *get(head_t *head, int index)
{
    int i = 0;
    node_t *tmp_node = head->head;

    if (head == NULL || head->head == NULL) {
        return NULL;
    }
    while (i < index) {
        if (tmp_node->next == NULL) {
            return NULL;
        }
        tmp_node = tmp_node->next;
        i += 1;
    }
    return tmp_node;
}
