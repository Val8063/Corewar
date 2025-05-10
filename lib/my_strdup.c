/*
** EPITECH PROJECT, 2024
** temp_stumper
** File description:
** my_strdup.c
*/

#include "corewar.h"
#include "op.h"

char *my_strdup(char *str)
{
    char *res = malloc(my_strlen(str) + 1);
    int i = 0;

    if (!res)
        return NULL;
    while (str[i] != '\0') {
        res[i] = str[i];
        i += 1;
    }
    res[i] = '\0';
    return res;
}
