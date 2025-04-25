/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include "struct.h"
#include "corewar.h"

static int display(int *memory)
{
    int i = 0;

    if (memory == NULL)
        return printf("memory null"), 0;
    while (i < MEM_SIZE) {
        for (int e = 0; (e < 32) && i < MEM_SIZE; e++) {
            printf("%i", memory[i]);
            i++;
        }
        printf("\n");
    }
}

int main(int ac, char **av)
{
    parsed_t *args = parse_args(ac - ARGS_SKIP, av + ARGS_SKIP);
    vm_t *vm = init_vm(ac, av);

    if (vm == NULL || args == NULL)
        return 84;
    display(vm->memory);
    free_vm(vm);
}
