/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** free.c
*/

#include "struct.h"

static void free_champion(champion_t *champion)
{
    if (champion == NULL)
        return;
    if (champion->file_name != NULL)
        free(champion->file_name);
    if (champion->code != NULL)
        free(champion->code);
    free(champion);
}

static void free_process(process_t *process)
{
    if (process == NULL)
        return;
    free(process);
}

void free_vm(vm_t *vm)
{
    int i;

    if (vm == NULL)
        return;
    if (vm->champions != NULL) {
        for (i = 0; i < vm->nb_champions; i++)
            free_champion(vm->champions[i]);
        free(vm->champions);
    }
    if (vm->process != NULL) {
        for (i = 0; i < vm->nb_process; i++)
            free_process(vm->process[i]);
        free(vm->process);
    }
    free(vm);
}
