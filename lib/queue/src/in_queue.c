/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myteams-mael.rabot
** File description:
** in_queue.c
*/

#include "../include/head.h"

bool in_queue(struct head_s *head, void *cmp)
{
    unsigned int i = 0;

    while (i < head->size(head)) {
        if (head->at(head, i) == cmp) {
            return true;
        }
        i += 1;
    }
    return false;
}
