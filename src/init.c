/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** init.c
*/

#include "corewar.h"
#include "struct.h"

static int *init_memory(vm_t *vm)
{
    int *memory = malloc(sizeof(int) * MEM_SIZE);
    process_t *proc;
    champion_t *champ;

    for (int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    for (int i = 0; i < vm->nb_process; i++) {
        proc = vm->process[i];
        champ = vm->champions[i];
        write_memory(memory, proc->ld_adress, champ->code_size, champ->code);
    }
    return memory;
}

static op_function_t *init_op_tab(void)
{
    op_function_t *op_func = malloc(sizeof(op_function_t) * 16);

    op_func[0] = &op_live;
    op_func[1] = &op_ld;
    op_func[2] = &op_st;
    op_func[3] = &op_add;
    op_func[4] = &op_sub;
    op_func[5] = &op_and;
    op_func[6] = &op_or;
    op_func[7] = &op_xor;
    op_func[8] = &op_zjump;
    op_func[9] = &op_ldi;
    op_func[10] = &op_sti;
    op_func[11] = &op_fork;
    op_func[12] = &op_lld;
    op_func[13] = &op_lldi;
    op_func[14] = &op_lfork;
    op_func[15] = &op_aff;
    return op_func;
}

static void normalize_champions(int nb_champs, champion_t **champs)
{
    for (int i = 0; i < nb_champs; i++) {
        if (champs[i]->ld_adress == -1) {
            champs[i]->ld_adress = (MEM_SIZE % nb_champs) * i;
        }
    }
}

static process_t *create_process(champion_t *champs)
{
    process_t *process = malloc(sizeof(process_t));

    process->carry = 0;
    process->id = champs->id;
    process->ld_adress = champs->ld_adress;
    process->pc = champs->ld_adress;
    process->wait = -1;
    process->reg[0] = process->id;
    for (int i = 1; i < REG_NUMBER; i++) {
        process->reg[i] = 0;
    }
    return process;
}

static process_t **init_process(vm_t *vm)
{
    process_t **process = malloc(sizeof(process_t *) * (vm->nb_champions * 4));

    for (int i = 0; i < vm->nb_champions; i++) {
        vm->process[i] = create_process(vm->champions[i]);
    }
    vm->nb_process = vm->nb_champions;
    return process;
}

vm_t *init_vm(char **args)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL)
        return NULL;
    normalize_champion(vm->nb_champions, vm->champions);
    vm->process = init_process(vm);
    vm->memory = init_memory(vm->process);
    vm->op_func = init_op_tab();
    return vm;
}
