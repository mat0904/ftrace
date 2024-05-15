/*
** EPITECH PROJECT, 2024
** B-NWP-400-LYN-4-1-myftp-mathieu.borel
** File description:
** split.c
*/

#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_len_array(const char *string, const char *delim)
{
    char *token = NULL;
    char *rest = malloc(PATH_MAX);
    unsigned int size = 0;

    strcpy(rest, string);
    if (rest == NULL) {
        printf("Failed to malloc\n");
        return -1;
    }
    token = strtok(rest, delim);
    while (token) {
        size += 1;
        token = strtok(NULL, delim);
    }
    free(rest);
    return size;
}

static void split_token(char **array, char *string, const char *delim)
{
    int i = 0;
    char *token = NULL;
    char *rest = malloc(PATH_MAX);

    strcpy(rest, string);
    array[i] = NULL;
    token = strtok(rest, delim);
    while (token) {
        array[i] = malloc(PATH_MAX);
        strcpy(array[i], token);
        array[i + 1] = NULL;
        i += 1;
        token = strtok(NULL, delim);
    }
}

char **split(const char *string, const char *delim)
{
    char *copy = malloc(PATH_MAX);
    char **array = NULL;
    int size = get_len_array(string, delim);

    if (size == -1) {
        return NULL;
    }
    strcpy(copy, string);
    if (copy == NULL) {
        return NULL;
    }
    array = malloc(sizeof(char *) * (size + 1));
    if (array == NULL) {
        free(copy);
        return NULL;
    }
    split_token(array, copy, delim);
    free(copy);
    return array;
}
