/*
** EPITECH PROJECT, 2024
** Robot Factory
** File description:
** my_strcmp.c
*/

#include "corewar.h"

/**
 * @brief   Compare deux chaînes de charactères.
 *
 * @param   s1    Première chaîne de charactères.
 * @param   s2   Deuxième chaîne de charcatères..
 *
 * @return  1: Différent.
 *          0: Egale.
 */
int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return 1;
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 1;
    return 0;
}

/**
 * @brief   Compare n charactères entre deux chaînes de charactères.
 *
 * @param   s1   Première chaîne de charactères.
 * @param   s2   Deuxième chaîne de charcatères.
 * @param   n    Nombre de charactères à comparer.
 *
 * @return  1: Différent.
 *          0: Egale.
 */
int my_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    for (i = 0; i < n && s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return 1;
    if (i < n && (s1[i] || s2[i]))
        return 1;
    return 0;
}
