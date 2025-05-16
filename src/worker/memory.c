/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** memory.c
*/

#include "corewar.h"

/*
** @brief  Ecris dans la mémoire
**
** @param  memory       La mémoire dans laquelle il faut écrire
** @param  start_adress Adresse ou écrire le premier byte
** @param  len          Taille en byte à écrire
** @param  element      Tableau de byte à écrire dans la mémoire
**
** @warning La mémoire est entièrement circulaire (négatif et positif)
*/
void write_memory(byte_t *memory, int start_adress, int len, byte_t *element)
{
    int adress = 0;

    for (int i = 0; i < len; i++) {
        adress = (start_adress + i) % MEM_SIZE;
        if (adress < 0)
            adress += MEM_SIZE;
        memory[adress] = element[i];
    }
}
