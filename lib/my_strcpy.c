/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-aurelien.demeusy
** File description:
** my_strcpy.c
*/

#include "corewar.h"
#include "op.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
