/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** vm.c
*/

#include "corewar.h"

static void delete_process(vm_t *vm, int ind)
{
    int i = 0;

    for (i = ind; i < vm->nb_process - 1; i++)
        vm->process[i] = vm->process[i + 1];
    vm->nb_process--;
}

static void kill_champ(vm_t *vm, int id)
{
    int i = 0;

    while (i < vm->nb_process) {
        if (vm->process[i]->id == id)
            delete_process(vm, i);
        else
            i++;
    }
}

static void verify_live(vm_t *vm, champion_t **champs, int actual_cycle)
{
    int last_live;
    int min_cycle = actual_cycle - vm->cycle_to_die;

    for (int i = 0; i < vm->nb_alive; i++) {
        last_live = champs[i]->last_live;
        if (min_cycle > last_live) {
            kill_champ(vm, champs[i]->id);
            vm->nb_alive -= 1;
            my_printf("min_cycle : %i\n", min_cycle);
            my_printf("actual cycle : %i\n", vm->actual_cycle);
            my_printf("The player %i(%s) is dead. (last live : %i)\n",
            champs[i]->id, champs[i]->header.prog_name, last_live);
        }
    }
}

static void display_params(vm_t *vm, process_t *proc)
{
    my_printf("Player %i turn at cycle %i:\n", proc->id, vm->actual_cycle);
    /*my_printf("\topcode : %i\n", vm->mem[proc->pc]);
    for (int i = 0; i < op_tab[vm->mem[proc->pc] - 1].nbr_args; i++) {
        my_printf("\ttype : %i\n", proc->params_type[i]);
        my_printf("\tparam : %i\n", proc->params[i]);
    }*/
}

static void turn(vm_t *vm, process_t *process)
{
    int opcode = vm->mem[process->pc % MEM_SIZE];

    if (process->wait == 0) {
        if (opcode >= 1 && opcode <= 16) {
            display_params(vm, process);
            op_func[opcode - 1](vm, process);
        }
    }
    if (process->wait == -1) {
        process->wait = op_tab[vm->mem[process->pc % MEM_SIZE] + 1].nbr_cycles;
    }
    process->wait -= 1;
}

void launch_vm(vm_t *vm)
{
    dump_memory(vm->mem);
    while (vm->nb_alive > 1) {
        if (vm->actual_cycle % vm->cycle_to_die == 0)
            verify_live(vm, vm->champions, vm->actual_cycle);
        for (int i = 0; i < vm->nb_process; i++)
            turn(vm, vm->process[i]);
        vm->actual_cycle++;
    }
    my_printf("The player %i(%s) has won.\n",
            vm->process[0]->src->id, vm->process[0]->src->header.prog_name);
    return;
}
