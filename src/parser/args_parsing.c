/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** parsing.c
*/

#include "struct.h"
#include "corewar.h"

int is_cor_file(const char *filename)
{
    size_t len = my_strlen(filename);

    if (len < 5)
        return 0;
    return my_strcmp(filename + len - 4, ".cor") == 0;
}

static int init_args_struct(parsed_t *args, int argc, char **argv)
{
    args->champions = malloc(sizeof(champion_t) * MAX_CHAMPIONS);
    if (!args->champions)
        return print_e("Erreur : malloc échoué pour champions\n"), -1;
    args->nb_champions = 0;
    args->dump_cycle = -1;
    args->max_champions = MAX_CHAMPIONS;
    args->log = 0;
    args->argc = argc;
    args->argv = argv;
    return 1;
}

static int handle_dump_flag(parsed_t *args, char **argv, int *i, int argc)
{
    if (*i + 1 >= argc)
        return print_e("Erreur : -dump sans valeur\n"), -1;
    (*i)++;
    args->dump_cycle = my_atoi(argv[*i]);
    (*i)++;
    return 1;
}

static int handle_flag_value(parsed_t *args, int *dest,
    int *i, const char *flag)
{
    if (*i + 1 >= args->argc)
        return print_e("Erreur : %s sans valeur\n", flag), -1;
    (*i)++;
    *dest = my_atoi(args->argv[*i]);
    (*i)++;
    return 1;
}

static int find_first_available_id(parsed_t *args)
{
    int used_ids[MAX_CHAMPIONS] = {0};

    for (int i = 0; i < args->nb_champions; i++) {
        if (args->champions[i]->id > 0 &&
        args->champions[i]->id <= MAX_CHAMPIONS)
            used_ids[args->champions[i]->id - 1] = 1;
    }
    for (int i = 0; i < MAX_CHAMPIONS; i++) {
        if (used_ids[i] == 0)
            return i + 1;
    }
    return -1;
}

static int handle_champion(parsed_t *args, char *filename,
    int *tmp_id, int *tmp_addr)
{
    champion_t *new = malloc(sizeof(champion_t));

    if (!new)
        return print_e("Erreur : malloc échoué pour champion\n"), -1;
    if (*tmp_id == -1 || *tmp_id < 0)
        new->id = find_first_available_id(args);
    else
        new->id = *tmp_id;
    new->file_name = my_strdup(filename);
    new->ld_adress = *tmp_addr;
    new->code = NULL;
    new->code_size = 0;
    new->last_live = 0;
    my_memset(&new->header, 0, sizeof(header_t));
    args->champions[args->nb_champions] = new;
    args->nb_champions += 1;
    *tmp_addr = -1;
    *tmp_id = -1;
    return 1;
}

static int parse_arg(parsed_t *args, int *i,
    int *tmp_id, int *tmp_addr)
{
    if (my_strcmp(args->argv[*i], "-dump") == 0)
        return handle_dump_flag(args, args->argv, i, args->argc);
    if (my_strcmp(args->argv[*i], "-n") == 0)
        return handle_flag_value(args, tmp_id, i, "-n");
    if (my_strcmp(args->argv[*i], "-a") == 0)
        return handle_flag_value(args, tmp_addr, i, "-a");
    if (my_strcmp(args->argv[*i], "-log") == 0) {
        (*i)++;
        args->log = 1;
        return 1;
    }
    if (is_cor_file(args->argv[*i])) {
        if (args->nb_champions >= args->max_champions)
            return print_e("Trop de champions\n"), -1;
        handle_champion(args, args->argv[*i], tmp_id, tmp_addr);
        (*i)++;
        return 1;
    }
    return print_e("Argument inconnu ou invalide : %s\n", args->argv[*i]), -1;
}

parsed_t *parse_args(int argc, char **argv)
{
    int i = 1;
    int tmp_id = -1;
    int tmp_addr = -1;
    parsed_t *args = malloc(sizeof(parsed_t));

    if (!args) {
        print_e("Erreur : malloc échoué pour parsed_t\n");
        return NULL;
    }
    if (init_args_struct(args, argc, argv) == -1)
        return free(args), NULL;
    while (i < argc) {
        if (parse_arg(args, &i, &tmp_id, &tmp_addr) == -1)
            return free_parsed(args), NULL;
    }
    if (parse_all_champions(args) == -1)
        return free_parsed(args), NULL;
    return args;
}
