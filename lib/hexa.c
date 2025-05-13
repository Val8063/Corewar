/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** hexa.c
*/

#include "corewar.h"

static char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char result[len];

    for (int n = 0; n < len + 1; n++) {
        result[n] = str[(len - 1) - n];
    }
    for (int i = 0; i < len + 1; i++) {
        str[i] = result[i];
    }
    return str;
}

static char convert_letter(int nb)
{
    if (nb <= 9) {
        return nb + 48;
    } else {
        return nb + 65 - 10;
    }
}

char *convert_to_16(int quotient)
{
    char *result;
    int reste = 0;
    int i = 0;

    result = malloc(sizeof(char) * 3);
    if (quotient > 255)
        return result;
    for (; i < 2; i++) {
        reste = quotient % 16;
        result[i] = convert_letter(reste);
        quotient = quotient / 16;
    }
    result[i] = '\0';
    return my_revstr(result);
}
