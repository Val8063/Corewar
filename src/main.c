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

    if (memory == NULL)
        return;
    while (i < MEM_SIZE) {
        for (int e = 0; (e < 32) && i < MEM_SIZE; e++) {
            my_printf("%i", memory[i]);
            i++;
        }
        my_printf("\n");
    }
    return;
}

int main(int ac, char **av)
{
    parsed_t *args = parse_args(ac, av);
    vm_t *vm = init_vm(av, ac);

    if (args == NULL || vm == NULL)
        return 84;
    launch_vm(vm);
    free_vm(vm);
    return 0;
}
