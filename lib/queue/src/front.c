/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** front.c
*/

#include "../include/head.h"

void *front(head_t *head)
{
    if (head == NULL || head->head == NULL) {
        return NULL;
    }
    return head->head->data;
}
