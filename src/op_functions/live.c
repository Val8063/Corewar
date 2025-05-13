/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** live.c
*/

#include "corewar.h"

void op_live(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int id = process->params[0];
    static int nbr_live = 0;

    process->src->last_live = vm->actual_cycle;
    my_printf("\tThe player %i(%s) is alive.\n", id,
        process->src->header.prog_name);
        nbr_live++;
    if (nbr_live % NBR_LIVE == 0 && nbr_live != 0)
        vm->cycle_to_die -= CYCLE_DELTA;
    process->pc += inst_size;
    return;
}
