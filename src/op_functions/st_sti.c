/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** st_sti.c
*/

#include "corewar.h"

static void check_reg(int *value1, int *value2, process_t *proc)
{
    if (proc->params_type[1] == T_REG) {
        *value1 = proc->reg[(*value1) - 1];
    }
    if (proc->params_type[2] == T_REG) {
        *value2 = proc->reg[(*value2) - 1];
    }
}

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
    process->pc += inst_size;
}

void op_sti(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int reg_value;
    int value2 = process->params[1];
    int value3 = process->params[2];
    int addr = 0;

    if (process->params[0] >= 1 && process->params[0] <= REG_NUMBER)
        reg_value = process->reg[process->params[0] - 1];
    parse_indirect(vm, process);
    check_reg(&value2, &value3, process);
    addr = (process->pc + ((value2 + value3) % IDX_MOD)) % MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
    write_memory(vm->mem, addr, REG_SIZE, int_to_bytes(reg_value, REG_SIZE));
    process->carry = (reg_value == 0);
    if (vm->log)
        my_printf("\tsti: r%i (%i) -> addr (%i + %i) = %i, wr %i, carry %i\n",
        process->params[0], reg_value, value2, value3, addr, reg_value,
        process->carry);
    process->pc += inst_size;
}
