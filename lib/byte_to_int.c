/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** byte_to_int.c
*/

#include "corewar.h"

int bytes_to_int(const byte_t *bytes, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++) {
        result <<= 8;
        result |= bytes[i];
    }
    return result;
}

byte_t *int_to_bytes(int value, int size)
{
    byte_t *bytes = malloc(size);

    if (!bytes)
        return NULL;
    for (int i = size - 1; i >= 0; i--) {
        bytes[i] = value & 0xFF;
        value >>= 8;
    }
    return bytes;
}
