/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_FUNC
    #define COREWAR_FUNC

// LIB
int my_strlen(char const *str);
int my_printf(const char *format, ...);
int print_e(const char *format, ...);

// PARSER
parsed_t *parse_args(int ac, char **av, parsed_t *parsed);
// int display_parsed_struct(parsed_t *parsed);

// INIT
vm_t *init_vm(int argc, char **argv);

// FREE
void free_vm(vm_t *vm);

#endif
