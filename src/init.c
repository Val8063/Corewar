/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** init.c
*/

#include "struct.h"

static int *init_memory(void)
{
    int *memory = malloc(sizeof(int) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    return memory;
}

vm_t *init_vm(char **args)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL)
        return NULL;
    vm->memory = init_memory();
    return vm;
}
