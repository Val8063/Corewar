/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include "struct.h"
#include "corewar.h"

int main(int ac, char **av)
{
    parsed_t *args = parse_args(ac, av);
    vm_t *vm = init_vm(av);

    if (args == NULL || vm == NULL)
        return 84;
    launch_vm(vm);
    free_vm(vm);
    return 0;
}
