/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** aff.c
*/

#include "corewar.h"

void op_aff(vm_t *vm, process_t *process)
{
    int inst_size = parse_param(vm, process);
    int character = process->reg[process->params[0] - 1];

    my_printf("%c", character % 256);
    process->pc += inst_size;
}
