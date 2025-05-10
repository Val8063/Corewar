/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-corewar-leo.cottaz
** File description:
** my_atoi.c
*/

/**
 * @brief Check if a character is a digit
 * @param c Character to check
 * @return 1 if the character is a digit, 0 otherwise
 */
static int my_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * @brief Convert a string to an integer
 * @param str String to convert
 * @return The integer value
 */
int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
    str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    while (my_isdigit(str[i])) {
        if (result > (2147483647 - (str[i] - '0')) / 10)
            return (sign == 1) ? 2147483647 : -2147483648;
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
