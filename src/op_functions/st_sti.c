/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** st_sti.c
*/

#include "corewar.h"

static void check_reg(int *value0, int *value1, int *value2, process_t *proc)
{
    if (proc->params_type[0] == T_REG) {
        if (*value0 >= 1 && *value0 <= REG_NUMBER)
            *value0 = proc->reg[(*value0) - 1];
        else
            *value0 = 0;
    }
    if (proc->params_type[1] == T_REG) {
        if (*value1 >= 1 && *value1 <= REG_NUMBER)
            *value1 = proc->reg[(*value1) - 1];
        else
            *value1 = 0;
    }
    if (proc->params_type[2] == T_REG) {
        if (*value2 >= 1 && *value2 <= REG_NUMBER)
            *value2 = proc->reg[(*value2) - 1];
        else
            *value2 = 0;
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

static int compute_addr_and_write(vm_t *vm, process_t *process,
    sti_values_t val)
{
    byte_t *bytes;
    int addr = (process->pc + ((val.val2 + val.val3) % IDX_MOD)) % MEM_SIZE;

    if (addr < 0)
        addr += MEM_SIZE;
    bytes = int_to_bytes(val.val1, REG_SIZE);
    write_memory(vm->mem, addr, REG_SIZE, bytes);
    free(bytes);
    process->carry = (val.val1 == 0);
    return addr;
}

void op_sti(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    sti_values_t vals = { process->params[0], process->params[1],
        process->params[2] };
    int addr;

    parse_indirect(vm, process);
    check_reg(&vals.val1, &vals.val2, &vals.val3, process);
    addr = compute_addr_and_write(vm, process, vals);
    if (vm->log) {
        my_printf("\tsti: r%i (%i) -> addr (%i + %i) = %i, wr %i, carry %i\n",
                process->params[0], vals.val1, vals.val2, vals.val3,
                addr, vals.val1, process->carry);
    }
    process->pc += inst_size;
}
