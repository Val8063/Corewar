/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** struct.h
*/

#include "op.h"

#ifndef STRUCT_COREWAR
    #define STRUCT_COREWAR

typedef uint8_t byte_t;

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
    char *file_name;
    int id;
    int ld_adress;
    char *name;
    byte_t *code;
    int code_size;
} champion_t;

typedef struct {
    int id;
    int ld_adress;
    int reg[REG_NUMBER];
    int pc;
    int carry;
} process_t;

struct vm_s;
typedef struct vm_s vm_t;
typedef void (*op_functions)(vm_t *, process_t *);

typedef struct vm_s {
    champion_t **champions;
    int dp_cyc;
    int *memory;
    op_functions *op_func;
} vm_t;

typedef struct {
    champion_t **champions;
    int nb_champions;
    int dump_cycle;
    int max_champions;
    int argc;
    char **argv;
} parsed_t;

#endif
