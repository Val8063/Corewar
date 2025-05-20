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
void *my_memcpy(void *des, const void *source, size_t size);
void *my_memset(void *ptr, int value, size_t num);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);
int my_atoi(const char *str);
void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(const char *s1, const char *s2, int n);
int bytes_to_int(const byte_t *bytes, int size);
byte_t *int_to_bytes(int value, int size);
void convert_to_16(int quotient, char *buffer);

// PARSER

int display_parsed_structure(parsed_t *parsed);  // Nom corrigé
int parse_champion_file(const char *filename, champion_t *champion);
int parse_all_champions(parsed_t *parsed);
parsed_t *parse_args(int argc, char **argv);
// int display_parsed_struct(parsed_t *parsed);
int parse_param(vm_t *vm, process_t *process);
void parse_indirect(vm_t *vm, process_t *proc);
void parse_indirect_without_idx(vm_t *vm, process_t *proc);



// INIT

vm_t *init_vm(char **args, int argc);



// FREE

void free_vm(vm_t *vm);
void free_parsed(parsed_t *parsed);


// RUN

void launch_vm(vm_t *vm);



// MEMORY

void write_memory(byte_t *memory, int start_adress,
    int len, byte_t *element);
void dump_memory(byte_t *memory);



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
