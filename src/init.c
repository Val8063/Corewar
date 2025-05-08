/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** init.c
*/

#include "corewar.h"
#include "struct.h"

static int *init_memory(void)
{
    int *memory = malloc(sizeof(int) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        memory[i] = 0;
    return memory;
}

static op_functions *init_op_tab(void)
{
    op_functions *op_func = malloc(sizeof(op_functions) * 16);

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

vm_t *init_vm(char **args)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL)
        return NULL;
    vm->memory = init_memory();
    vm->op_func = init_op_tab();
    return vm;
}
