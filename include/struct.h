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
    int has_index;
    int has_coding_byte;
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
    char *file_name;      // Nom du fichier du champion
    header_t header;      // En-tête du champion
    int id;               // ID du champion dans la VM
    int ld_adress;        // Adresse de chargement
    byte_t *code;         // Code binaire du champion
    int code_size;        // Taille du code binaire
    int pc;               // Program counter
    int carry;            // Carry flag
    int last_live;        // Dernier cycle où le champion a exécuté 'live'
    int reg[REG_NUMBER];  // Registres
} champion_t;

typedef struct {
    champion_t *champion; // Le champion auquel ce processus appartient
    int id;               // ID unique du processus
    int ld_adress;        // Adresse de chargement
    int reg[REG_NUMBER];  // Registres du processus
    int pc;               // Program counter
    int wait;             // Cycles à attendre avant la prochaine instruction
    int carry;            // Carry flag
    int params[MAX_ARGS_NUMBER];     // Paramètres de l'instruction en cours
    int params_type[MAX_ARGS_NUMBER]; // Types des paramètres de l'instruction
    int alive;            // Si le processus est encore vivant
} process_t;

struct vm_s;
typedef struct vm_s vm_t;
typedef void (*op_function_t)(vm_t *, process_t *);

extern const op_function_t op_func[];

typedef struct vm_s {
    champion_t **champions;
    int nb_champions;
    int nb_alive;
    process_t **process;
    int actual_cycle;
    int nb_process;
    int dp_cyc;
    int cycle_to_die;
    byte_t *mem;
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
