/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** fork_lfork.c
*/

#include "corewar.h"

void fork_process(vm_t *vm, process_t *process, int new_pc)
{
    process_t *new = malloc(sizeof(process_t));

    if (!new)
        return;
    new->carry = process->carry;
    new->id = process->id;
    new->pc = new_pc;
    new->src = process->src;
    new->wait = -1;
    for (int i = 0; i < REG_NUMBER; i++)
        new->reg[i] = process->reg[i];
    vm->nb_process += 1;
    vm->process = realloc(vm->process, vm->nb_process * sizeof(process_t *));
    if (!vm->process) {
        print_e("Une erreur critique est survenue pendant le fork");
        return;
    }
    vm->process[vm->nb_process - 1] = new;
}

void op_fork(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int offset = process->params[0] % IDX_MOD;
    int new_pc = (process->pc + offset) % MEM_SIZE;

    if (new_pc < 0)
        new_pc += MEM_SIZE;
    fork_process(vm, process, new_pc);
    my_printf("\tfork: from pc %i with offset %i -> new pc %i\n",
        process->pc, offset, new_pc);
    process->pc += inst_size;
}

void op_lfork(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int offset = process->params[0];
    int new_pc = (process->pc + offset) % MEM_SIZE;

    if (new_pc < 0)
        new_pc += MEM_SIZE;
    fork_process(vm, process, new_pc);
    my_printf("\tfork: from pc %i with offset %i -> new pc %i\n",
        process->pc, offset, new_pc);
    process->pc += inst_size;
}
