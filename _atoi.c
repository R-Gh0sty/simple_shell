#include "shell.h"

/**
 * check_interactive - Checks if the shell is in interactive mode
 * @info: Pointer to the info_t structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int check_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - Checks if a character is a delimiter
 * @c: The character to check
 * @delimiters: The delimiter string
 *
 * Return: 1 if 'c' is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delimiters)
{
    while (*delimiters)
    {
        if (*delimiters++ == c)
            return (1);
    }
    return (0);
}

/**
 * is_alphabetic - Checks if a character is alphabetic
 * @c: The character to check
 *
 * Return: 1 if 'c' is alphabetic, 0 otherwise
 */
int is_alphabetic(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * custom_atoi - Converts a string to an integer
 * @s: The string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int custom_atoi(char *s)
{
    int i, sign = 1, flag = 0, result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    return (sign == -1 ? -result : result);
}

/* Signature: Reda DOHNANE */

