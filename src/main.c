/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include "struct.h"
#include "op.h"
#include "corewar.h"

void dump_memory(byte_t *memory)
{
    int i = 0;
    char hexa[3];

    if (memory == NULL)
        return;
    while (i < MEM_SIZE) {
        for (int e = 0; (e < 32) && i < MEM_SIZE; e++) {
            convert_to_16(memory[i], hexa);
            my_printf("%s", hexa);
            i++;
        }
        my_printf("\n");
    }
    return;
}

int main(int ac, char **av)
{
    vm_t *vm = init_vm(av, ac);

    if (vm == NULL)
        return 84;
    dump_memory(vm->mem);
    launch_vm(vm);
    dump_memory(vm->mem);
    free(vm->parsed);
    free_vm(vm);
    return 0;
}
