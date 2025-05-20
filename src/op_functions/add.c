/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** add.c
*/

#include "corewar.h"

void op_add(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int reg1 = process->reg[process->params[0] - 1];
    int reg2 = process->reg[process->params[1] - 1];
    int result = reg1 + reg2;

    process->reg[process->params[2] - 1] = result;
    process->carry = (result == 0);
    if (vm->log)
        my_printf("\tadd: r%i %i + r%i %i = r%i %i\n",
        process->params[0], reg1, process->params[1], reg2, process->params[2],
        process->reg[process->params[2] - 1]);
    process->pc += inst_size;
}
