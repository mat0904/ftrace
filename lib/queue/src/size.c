/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** size.c
*/

#include "../include/head.h"

unsigned int size(head_t *head)
{
    unsigned int size = 0;
    node_t *tmp_node = head->head;

    if (head == NULL || head->head == NULL) {
        return 0;
    }
    while (tmp_node != NULL) {
        tmp_node = tmp_node->next;
        size += 1;
    }
    return size;
}
