/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-aurelien.demeusy
** File description:
** my_memcpy.c
*/

#include "corewar.h"
#include "op.h"

void *my_memcpy(void *des, const void *source, size_t size)
{
    char *ptr = des;
    int end = 0;

    if (des == NULL || source == NULL)
        return NULL;
    for (size_t index = 0; index < size; index++) {
        if (end == 1 || ((char *)source)[index] == '\0') {
            end = 1;
            ptr[index] = '\0';
        }
        ptr[index] = ((char *)source)[index];
    }
    return (void *)ptr;
}
