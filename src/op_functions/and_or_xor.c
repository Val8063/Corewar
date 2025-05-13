/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** conditionnal.c
*/

#include "corewar.h"

static void check_reg(int *value1, int *value2, process_t *proc)
{
    if (proc->params_type[0] == T_REG) {
        *value1 = proc->reg[(*value1) - 1];
    }
    if (proc->params_type[1] == T_REG) {
        *value2 = proc->reg[(*value2) - 1];
    }
}

void op_and(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int value1 = process->params[0];
    int value2 = process->params[1];
    int arg3 = process->params[2];
    int result = 0;

    check_reg(&value1, &value2, process);
    result = value1 & value2;
    process->reg[arg3 - 1] = result & 0xFF;
    process->carry = (result == 0);
    process->pc += inst_size;
    my_printf("\tand: entre %i et %i, result : %i dans r%i",
        value1, value2, result, arg3);
}

void op_or(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int value1 = process->params[0];
    int value2 = process->params[1];
    int arg3 = process->params[2];
    int result = 0;

    check_reg(&value1, &value2, process);
    result = value1 | value2;
    process->reg[arg3 - 1] = result & 0xFF;
    process->carry = (result == 0);
    process->pc += inst_size;
    my_printf("\tor: entre %i et %i, result : %i dans r%i",
        value1, value2, result, arg3);
}

void op_xor(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int value1 = process->params[0];
    int value2 = process->params[1];
    int arg3 = process->params[2];
    int result = 0;

    check_reg(&value1, &value2, process);
    result = value1 ^ value2;
    process->reg[arg3 - 1] = result & 0xFF;
    process->carry = (result == 0);
    process->pc += inst_size;
    my_printf("\txor: entre %i et %i, result : %i dans r%i",
        value1, value2, result, arg3);
}
