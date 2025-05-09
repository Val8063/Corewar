/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** op.c
*/

#include "corewar.h"
#include "struct.h"

const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, 0, 0, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 0, 1, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 0, 1, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 0, 1, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 0, 1, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 0,
        1, "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 0,
        1, "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 0,
        1, "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, 1, 0, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 1,
        "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 1,
        "store index"},
    {"fork", 1, {T_DIR}, 12, 800, 1, 0, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 0, 1, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 1,
        "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, 1, 0, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, 0, 1, "aff"},
    {0, 0, {0}, 0, 0, 0, 0, 0}
};

const op_function_t op_func[] = {
    &op_live,
    &op_ld,
    &op_st,
    &op_add,
    &op_sub,
    &op_and,
    &op_or,
    &op_xor,
    &op_zjump,
    &op_ldi,
    &op_sti,
    &op_fork,
    &op_lld,
    &op_lldi,
    &op_lfork,
    &op_aff
};
