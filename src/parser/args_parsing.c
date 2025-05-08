/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** parsing.c
*/

#include "struct.h"

int is_cor_file(const char *filename)
{
    size_t len = strlen(filename);

    if (len < 5)
        return 0;
    return strcmp(filename + len - 4, ".cor") == 0;
}

static void init_args_struct(parsed_t *args, int argc, char **argv)
{
    args->champions = malloc(sizeof(champion_t) * MAX_CHAMPIONS);
    if (!args->champions) {
        fprintf(stderr, "Erreur : malloc échoué pour champions\n");
        exit(84);
    }
    args->nb_champions = 0;
    args->dump_cycle = -1;
    args->max_champions = MAX_CHAMPIONS;
    args->argc = argc;
    args->argv = argv;
}

static void handle_dump_flag(parsed_t *args, char **argv, int *i, int argc)
{
    if (*i + 1 >= argc) {
        fprintf(stderr, "Erreur : -dump sans valeur\n");
        exit(84);
    }
    (*i)++;
    args->dump_cycle = atoi(argv[*i]);
    (*i)++;
}

static void handle_flag_value(parsed_t *args, int *dest,
    int *i, const char *flag)
{
    if (*i + 1 >= args->argc) {
        fprintf(stderr, "Erreur : %s sans valeur\n", flag);
        exit(84);
    }
    (*i)++;
    *dest = atoi(args->argv[*i]);
    (*i)++;
}

static void handle_champion(parsed_t *args, char *filename,
    int *tmp_id, int *tmp_addr)
{
    champion_t *new = malloc(sizeof(champion_t));

    if (!new) {
        fprintf(stderr, "Erreur : malloc échoué pour champion\n");
        exit(84);
    }
    new->file_name = strdup(filename);
    new->id = *tmp_id;
    new->ld_adress = *tmp_addr;
    args->champions[args->nb_champions] = new;
    args->nb_champions += 1;
    *tmp_id = -1;
    *tmp_addr = -1;
}

static void parse_arg(parsed_t *args, int *i,
    int *tmp_id, int *tmp_addr)
{
    if (strcmp(args->argv[*i], "-dump") == 0)
        return handle_dump_flag(args, args->argv, i, args->argc);
    if (strcmp(args->argv[*i], "-n") == 0)
        return handle_flag_value(args, tmp_id, i, "-n");
    if (strcmp(args->argv[*i], "-a") == 0)
        return handle_flag_value(args, tmp_addr, i, "-a");
    if (is_cor_file(args->argv[*i])) {
        if (args->nb_champions >= args->max_champions) {
            fprintf(stderr, "Trop de champions\n");
            exit(84);
        }
        handle_champion(args, args->argv[*i], tmp_id, tmp_addr);
        (*i)++;
        return;
    }
    fprintf(stderr, "Argument inconnu ou invalide : %s\n", args->argv[*i]);
    exit(84);
}

parsed_t *parse_args(int argc, char **argv)
{
    int i = 1;
    int tmp_id = -1;
    int tmp_addr = -1;
    parsed_t *args = malloc(sizeof(parsed_t));

    init_args_struct(args, argc, argv);
    while (i < argc) {
        parse_arg(args, &i, &tmp_id, &tmp_addr);
    }
    return 0;
}
