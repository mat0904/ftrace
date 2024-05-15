/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** back.c
*/

#include "../include/head.h"

void *back(head_t *head)
{
    node_t *tmp_node = head->head;

    if (head == NULL || head->head == NULL) {
        return NULL;
    }
    while (tmp_node->next != NULL) {
        tmp_node = tmp_node->next;
    }
    return tmp_node->data;
}
