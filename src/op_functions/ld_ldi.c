/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** ld_ldi.c
*/

#include "corewar.h"

void op_ld(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);

    parse_indirect(vm, process);
    if (1 <= process->params[1] && process->params[1] <= 16) {
        process->reg[process->params[1] - 1] = process->params[0];
        process->carry = (process->params[0] == 0);
    }
    my_printf("\tld: %i load dans r%i\n modification carry : %i",
        process->params[0], process->params[1] - 1, process->carry);
    process->pc += inst_size;
}

void op_ldi(vm_t *vm, process_t *process)
{
    return;
}
