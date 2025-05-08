/*
** EPITECH PROJECT, 2024
** Robot Factory
** File description:
** my_printf.c
*/

#include "op.h"
#include "corewar.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int count = 0;

    if (!str)
        return write(2, "(null)", 6), 0;
    write(1, str, my_strlen(str));
    return count;
}

static int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(- nb);
        count++;
    } else if (nb > 9) {
        count += my_put_nbr(nb / 10);
        count += my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + 48);
        count++;
    }
    return count;
}

static int apply(va_list ptr, char format, int count)
{
    switch (format) {
    case 'd':
    case 'i':
        count += my_put_nbr(va_arg(ptr, int));
        return count;
    case 's':
        count += my_putstr(va_arg(ptr, char *));
        return count;
    case 'c':
        my_putchar(va_arg(ptr, int));
        return count + 1;
    case '%':
        my_putchar('%');
        return count + 1;
    default:
        return -1;
    }
}

/*
 * @brief   Ecris dans stdout.
 *
 * @param   format  Chaîne de charactères avec les format identifiers.
 * @param   ...     Variables associées aux format identifiers.
 *
 * @return  Nombre de charactères affichés.
 */
int my_printf(const char *format, ...)
{
    va_list ptr;
    int count = 0;

    va_start(ptr, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            count = apply(ptr, format[i + 1], count);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
        if (count < 0) {
            return -1;
        }
    }
    return count;
}
