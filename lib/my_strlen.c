/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday04-aurelien.demeusy
** File description:
** my_strlen.c
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}
