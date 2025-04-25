/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** free.c
*/

#include "struct.h"

void free_vm(vm_t *vm)
{
    free(vm->memory);
    free(vm);
}
