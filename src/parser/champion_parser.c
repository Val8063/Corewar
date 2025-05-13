/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** champion_parser.c - Functions to parse champion files
*/

#include "struct.h"
#include "corewar.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Initialize a header structure
 * @param header Pointer to the header structure to initialize
 */
static void init_header(header_t *header)
{
    my_memset(header, 0, sizeof(header_t));
}

/**
 * @brief Read the magic number from a champion file
 * @param fd File descriptor
 * @param header Pointer to header structure
 * @return 0 on success, -1 on error
 */
static int read_magic(int fd, header_t *header)
{
    unsigned char buffer[4];

    if (read(fd, buffer, 4) != 4) {
        print_e("Erreur : Impossible de lire le magic number\n");
        return -1;
    }
    header->magic = (buffer[0] << 24) | (buffer[1] << 16) |
    (buffer[2] << 8) | buffer[3];
    if (header->magic != COREWAR_EXEC_MAGIC) {
        print_e("Erreur : Magic number invalide (0x%x)\n", header->magic);
        return -1;
    }
    return 0;
}

/**
 * @brief Read champion program name
 * @param fd File descriptor
 * @param header Pointer to header structure
 * @return 0 on success, -1 on error
 */
static int read_program_name(int fd, header_t *header)
{
    if (read(fd, header->prog_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH) {
        print_e("Erreur : Impossible de lire le nom du programme\n");
        return -1;
    }
    header->prog_name[PROG_NAME_LENGTH] = '\0';
    return 0;
}

/**
 * @brief Skip padding bytes
 * @param fd File descriptor
 * @return 0 on success, -1 on error
 */
static int skip_padding(int fd)
{
    unsigned char padding[4];

    if (read(fd, padding, 4) != 4) {
        print_e("Erreur : Impossible de lire le padding\n");
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        if (padding[i] != 0) {
            print_e("Avertissement : Padding non nul détecté\n");
            break;
        }
    }
    return 0;
}

/**
 * @brief Read program size
 * @param fd File descriptor
 * @param header Pointer to header structure
 * @return 0 on success, -1 on error
 */
static int read_program_size(int fd, header_t *header)
{
    unsigned char buffer[4];

    if (read(fd, buffer, 4) != 4) {
        print_e("Erreur: Impossible de lire la taille du programme\n");
        return -1;
    }
    header->prog_size = (buffer[0] << 24) | (buffer[1] << 16) |
    (buffer[2] << 8) | buffer[3];
    if (header->prog_size <= 0 || header->prog_size > MEM_SIZE) {
        print_e("Erreur : Taille du programme invalide\n");
        return -1;
    }
    return 0;
}

/**
 * @brief Read program comment
 * @param fd File descriptor
 * @param header Pointer to header structure
 * @return 0 on success, -1 on error
 */
static int read_comment(int fd, header_t *header)
{
    if (read(fd, header->comment, COMMENT_LENGTH) != COMMENT_LENGTH) {
        print_e("Erreur : Impossible de lire le commentaire\n");
        return -1;
    }
    header->comment[COMMENT_LENGTH] = '\0';
    return 0;
}

/**
 * @brief Read the complete header from a champion file
 * @param fd File descriptor
 * @param header Pointer to header structure
 * @return 0 on success, -1 on error
 */
static int read_header(int fd, header_t *header)
{
    init_header(header);
    if (read_magic(fd, header) == -1)
        return -1;
    if (read_program_name(fd, header) == -1)
        return -1;
    if (skip_padding(fd) == -1)
        return -1;
    if (read_program_size(fd, header) == -1)
        return -1;
    if (read_comment(fd, header) == -1)
        return -1;
    if (skip_padding(fd) == -1)
        return -1;
    return 0;
}

/**
 * @brief Read a champion's instructions from file
 * @param fd Open file descriptor for the champion file
 * @param prog_size The size of the program as specified in the header
 * @return Pointer to a buffer containing the instructions, or NULL on error
 */
static unsigned char *read_instructions(int fd, int prog_size)
{
    unsigned char *instructions = malloc(prog_size);

    if (!instructions) {
        print_e("Erreur: Échec d'allocation mémoire pour les instructions\n");
        return NULL;
    }
    if (read(fd, instructions, prog_size) != prog_size) {
        print_e("Erreur : Impossible de lire les instructions\n");
        free(instructions);
        return NULL;
    }
    return instructions;
}

/**
 * @brief Parse a champion file and load it into memory
 * @param filename Path to the champion file
 * @param champion Pointer to champion structure to fill
 * @return 0 on success, -1 on error
 */
int parse_champion_file(const char *filename, champion_t *champion)
{
    int fd = open(filename, O_RDONLY);
    header_t header;
    unsigned char *instructions = NULL;

    if (fd == -1) {
        return print_e("Erreur : Impossible d'ouvrir le fichier '%s'\n"
        , filename), -1;
    }
    if (read_header(fd, &header) == -1)
        return close(fd), -1;
    instructions = read_instructions(fd, header.prog_size);
    if (!instructions)
        return close(fd), -1;
    my_memcpy(&champion->header, &header, sizeof(header_t));
    if (champion->code != NULL)
        free(champion->code);
    champion->code = instructions;
    champion->code_size = header.prog_size;
    close(fd);
    return 0;
}

/**
 * @brief Parse all champion files and load their code
 * @param parsed Parsed arguments containing champion information
 * @return 0 on success, -1 on error
 */
int parse_all_champions(parsed_t *parsed)
{
    int success_count = 0;
    champion_t *champ = NULL;

    for (int i = 0; i < parsed->nb_champions; i++) {
        champ = parsed->champions[i];
        if (parse_champion_file(champ->file_name, champ) == -1) {
            print_e("Erreur lors du parsing du champion: %s\n",
            champ->file_name);
        } else {
            success_count++;
        }
    }
    if (success_count < parsed->nb_champions)
        print_e("Certains champions n'ont pas pu être chargés\n");
    if (success_count < 2)
        return print_e("Erreur: Il faut au moins 2 champions\n"), -1;
    return 0;
}
