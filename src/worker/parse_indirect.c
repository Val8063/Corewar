/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** parse_indirect.c
*/

#include "corewar.h"

void parse_indirect(vm_t *vm, process_t *proc)
{
    int op_code = vm->mem[proc->pc % MEM_SIZE] - 1;
    int nb_arg = op_tab[op_code].nbr_args;
    int addr = 0;

    for (int i = 0; i < nb_arg; i++) {
        if (proc->params_type[i] == T_IND) {
            addr = (proc->pc + (proc->params[i] % IDX_MOD)) % MEM_SIZE;
            addr += (addr < 0) ? MEM_SIZE : 0;
            proc->params[i] = bytes_to_int(&vm->mem[addr], DIR_SIZE);
        }
    }
}

void parse_indirect_without_idx(vm_t *vm, process_t *proc)
{
    int op_code = vm->mem[proc->pc % MEM_SIZE] - 1;
    int nb_arg = op_tab[op_code].nbr_args;
    int addr = 0;

    for (int i = 0; i < nb_arg; i++) {
        if (proc->params_type[i] == T_IND) {
            addr = (proc->pc + proc->params[i]) % MEM_SIZE;
            addr += (addr < 0) ? MEM_SIZE : 0;
            proc->params[i] = bytes_to_int(&vm->mem[addr], DIR_SIZE);
        }
    }
}
