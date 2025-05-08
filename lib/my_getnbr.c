/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday04-aurelien.demeusy
** File description:
** my_getnbr.c
*/

#include "op.h"

/**
 * @brief   Transforme une chaîne de charactère en entier.
 *
 * @param   str   Chaîne à transformer.
 *
 * @return  0 en cas de succès, -1 en cas d'erreur
 * @warning A la moindre erreur, INT_MAX sera retournée !.
 */
int my_getnbr(const char *str, int *result)
{
    int i = 0;
    int neg = 0;

    *result = 0;
    if (!str)
        return -1;
    if (str[0] == '-') {
        neg = 1;
        i++;
    } else if (str[0] == '+')
        i++;
    for (; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            *result = *result * 10 + (str[i] - '0');
        else
            return -1;
    if (neg)
        *result = *result * -1;
    return 0;
}
