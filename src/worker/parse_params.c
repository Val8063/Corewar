/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** parse_params.c
*/

#include "corewar.h"

static int check_param_types(int op_code, process_t *process)
{
    for (int i = 0; i < op_tab[op_code].nbr_args; ++i) {
        if (!(op_tab[op_code].type[i] & process->params_type[i]))
            return 0;
    }
    return 1;
}

static void decrypt_coding_byte(vm_t *vm, process_t *process)
{
    int op_code = vm->mem[process->pc % MEM_SIZE] - 1;
    int coding_byte = vm->mem[(process->pc + 1) % MEM_SIZE];
    byte_t param_type;

    for (int i = 0; i < op_tab[op_code].nbr_args; ++i) {
        param_type = (coding_byte >> (6 - 2 * i)) & 0x03;
        process->params_type[i] = param_type;
    }
}

static int get_size(int op_code, int type)
{
    if (type == T_DIR && op_tab[op_code].has_index == 1)
        return 2;
    switch (type) {
        case T_DIR:
            return DIR_SIZE;
        case T_IND:
            return IND_SIZE;
        case T_REG:
            return REG_SIZE;
        default:
            return 0;
    }
}

int parse_param(vm_t *vm, process_t *process)
{
    int op_code = vm->mem[process->pc % MEM_SIZE] - 1;
    int size;
    int offset = 1 + op_tab[op_code].has_coding_byte;

    if ((op_code + 1) < 1 || 16 < (op_code + 1))
        return -1;
    if (op_tab[op_code].has_coding_byte == 1) {
        decrypt_coding_byte(vm, process);
        if (!check_param_types(op_code, process))
            return -1;
    } else {
        process->params_type[0] = T_DIR;
    }
    for (int i = 0; i < op_tab[op_code].nbr_args; ++i) {
        size = get_size(op_code, process->params_type[i]);
        process->params[i] = bytes_to_int(
            &vm->mem[(process->pc + offset) % MEM_SIZE], size);
        offset += size;
    }
    return offset;
}
