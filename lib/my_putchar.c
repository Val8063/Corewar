/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday03-aurelien.demeusy
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
