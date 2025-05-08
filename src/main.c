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
    return 0;
}

int main(int ac, char **av)
{
    parsed_t *args = malloc(sizeof(parsed_t));
    vm_t *vm = NULL;

    if (args == NULL)
        return 84;
    parse_args(ac, av, args);
    vm = init_vm(ac, av);
    if (args == NULL)
        return 84;
    if (vm == NULL)
        return 84;
    display(vm->memory);
    free_vm(vm);
    return 0;
}
