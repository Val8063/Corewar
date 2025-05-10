/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-robotfactory-aurelien.demeusy
** File description:
** my_memset.c
*/

#include "corewar.h"
#include "op.h"

void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *p;

    if (ptr == NULL) {
        write(2, "Erreur : pointeur NULL\n", 22);
        return NULL;
    }
    if (num == 0)
        return ptr;
    p = ptr;
    for (size_t i = 0; i < num; i++)
        p[i] = (unsigned char)value;
    return ptr;
}
