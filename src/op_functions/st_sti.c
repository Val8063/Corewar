/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** st_sti.c
*/

#include "corewar.h"

void op_st(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int param1 = process->params[0];
    int param2 = process->params[1];
    int start_addr = (process->pc + (param2 % IDX_MOD)) % MEM_SIZE;
    byte_t *value = int_to_bytes(process->reg[param1 - 1], REG_SIZE);

    if (process->params_type[1] == T_REG) {
        process->reg[param2 - 1] = process->reg[param1 - 1];
    } else {
        if (start_addr < 0)
            start_addr += MEM_SIZE;
        write_memory(vm->mem, start_addr, REG_SIZE, value);
    }
    free(value);
}

void op_sti(vm_t *vm, process_t *process)
{
    return;
}
