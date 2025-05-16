/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** ld_ldi.c
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

void op_ld(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);

    parse_indirect(vm, process);
    if (1 <= process->params[1] && process->params[1] <= 16) {
        process->reg[process->params[1] - 1] = process->params[0];
        process->carry = (process->params[0] == 0);
    }
    if (vm->log)
        my_printf("\tld: %i load dans r%i\n modification carry : %i\n",
        process->params[0], process->params[1] - 1, process->carry);
    process->pc += inst_size;
}

void op_ldi(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int value1 = process->params[0];
    int value2 = process->params[1];
    int reg_id = process->params[2];
    int addr = 0;
    byte_t result = 0;

    parse_indirect(vm, process);
    check_reg(&value1, &value2, process);
    addr = (process->pc + ((value1 + value2) % IDX_MOD)) % MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
    result = vm->mem[addr];
    process->reg[reg_id - 1] = result;
    process->carry = (result == 0);
    if (vm->log)
        my_printf("\tldi: (%i + %i) -> addr %i, value %i into r%i, carry %i\n",
        value1, value2, addr, result, reg_id, process->carry);
    process->pc += inst_size;
}
