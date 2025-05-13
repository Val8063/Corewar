/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** zjump.c
*/

#include "corewar.h"

void op_zjump(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int offset = (int16_t)process->params[0] % IDX_MOD;

    if (process->carry == 1) {
        my_printf("\tzjump: ancien pc: %i, offset:%i", process->pc, offset);
        process->pc = (process->pc + offset) % MEM_SIZE;
        my_printf(" new pc: %i\n", process->pc);
    } else {
        process->pc = (process->pc + inst_size) % MEM_SIZE;
        my_printf("\tzjump: carry à 0 (zjump cancel)\n");
    }
    return;
}
