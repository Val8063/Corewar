/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** init.c
*/

#include "corewar.h"
#include "struct.h"

static byte_t *init_memory(vm_t *vm)
{
    byte_t *mem = malloc(sizeof(byte_t) * MEM_SIZE);
    process_t *proc;
    champion_t *champ;

    for (int i = 0; i < MEM_SIZE; i++)
        mem[i] = 0;
    for (int i = 0; i < vm->nb_process; i++) {
        proc = vm->process[i];
        champ = proc->src;
        write_memory(mem, proc->ld_adress, champ->code_size, champ->code);
    }
    return mem;
}

static void normalize_champions(int nb_champs, champion_t **champs)
{
    for (int i = 0; i < nb_champs; i++) {
        if (champs[i]->ld_adress == -1) {
            champs[i]->ld_adress = (MEM_SIZE / nb_champs) * i;
        }
    }
}

static process_t *create_process(champion_t *champ)
{
    process_t *process = malloc(sizeof(process_t));

    process->src = champ;
    process->carry = 0;
    process->id = champ->id;
    process->ld_adress = champ->ld_adress;
    process->pc = champ->ld_adress;
    process->wait = -1;
    for (int i = 1; i < REG_NUMBER; i++) {
        process->reg[i] = 0;
    }
    process->reg[0] = process->id;
    return process;
}

static process_t **init_process(vm_t *vm)
{
    process_t **process = malloc(sizeof(process_t *) * (vm->nb_champions * 4));

    if (process == NULL)
        return NULL;
    for (int i = 0; i < vm->nb_champions; i++) {
        process[i] = create_process(vm->champions[i]);
    }
    vm->nb_process = vm->nb_champions;
    return process;
}

vm_t *init_vm(char **args, int argc)
{
    vm_t *vm = malloc(sizeof(vm_t));
    parsed_t *parsed;

    if (vm == NULL)
        return NULL;
    parsed = parse_args(argc, args);
    if (parsed == NULL)
        return free(vm), NULL;
    vm->champions = parsed->champions;
    vm->nb_champions = parsed->nb_champions;
    vm->dp_cyc = parsed->dump_cycle;
    normalize_champions(vm->nb_champions, vm->champions);
    vm->nb_alive = vm->nb_champions;
    vm->actual_cycle = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->process = init_process(vm);
    vm->mem = init_memory(vm);
    my_printf("Nombre de champions : %i\n", vm->nb_champions);
    my_printf("Nombre de process : %i\n", vm->nb_process);
    return vm;
}
