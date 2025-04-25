/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** struct.h
*/

#include "op.h"

#ifndef STRUCT_COREWAR
    #define STRUCT_COREWAR

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

extern const op_t op_tab[];

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct {
    int *reg[REG_NUMBER];
    int pc;
    int carry;
} champion_t;

typedef struct {
    champion_t **champions;
    int *memory;
} vm_t;

typedef struct {
    int *id;
    int *ld_adress;
    char **file_name;
} parsed_t;

#endif
