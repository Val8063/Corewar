/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** corewar.h
*/

#include "struct.h"

#ifndef COREWAR_FUNC
    #define COREWAR_FUNC

// LIB
int my_strlen(char const *str);
int my_getnbr(const char *str, int *result);
int my_printf(const char *format, ...);
int print_e(const char *format, ...);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(const char *s1, const char *s2, int n);

// PARSER
parsed_t *parse_args(int argc, char **argv);
// int display_parsed_struct(parsed_t *parsed);

// INIT
vm_t *init_vm(char **args);

// FREE
void free_vm(vm_t *vm);

// RUN
void launch_vm(vm_t *vm);

// OP_FUNCTIONS
void op_live(vm_t *vm, process_t *process);
void op_ld(vm_t *vm, process_t *process);
void op_st(vm_t *vm, process_t *process);
void op_add(vm_t *vm, process_t *process);
void op_sub(vm_t *vm, process_t *process);
void op_and(vm_t *vm, process_t *process);
void op_or(vm_t *vm, process_t *process);
void op_xor(vm_t *vm, process_t *process);
void op_zjump(vm_t *vm, process_t *process);
void op_ldi(vm_t *vm, process_t *process);
void op_sti(vm_t *vm, process_t *process);
void op_fork(vm_t *vm, process_t *process);
void op_lld(vm_t *vm, process_t *process);
void op_lldi(vm_t *vm, process_t *process);
void op_lfork(vm_t *vm, process_t *process);
void op_aff(vm_t *vm, process_t *process);

#endif
