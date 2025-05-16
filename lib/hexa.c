/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** hexa.c
*/

#include "corewar.h"

static char convert_letter(int nb)
{
    if (nb <= 9) {
        return nb + 48;
    } else {
        return nb + 65 - 10;
    }
}

void convert_to_16(int quotient, char *buffer)
{
    if (!buffer)
        return;
    buffer[0] = '0';
    buffer[1] = '0';
    buffer[2] = '\0';
    if (quotient < 0 || quotient > 255)
        return;
    buffer[1] = convert_letter(quotient % 16);
    buffer[0] = convert_letter((quotient / 16) % 16);
}
