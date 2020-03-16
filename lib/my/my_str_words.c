/*
** EPITECH PROJECT, 2019
** my str words
** File description:
** sd
*/

#include "my.h"

int my_str_words(char const *str)
{
    int i = 0;
    int rep = 0;
    int y = 0;

    while ( str[i] != '\0' )
    {
        if (my_char_isalphanum(str[i]) && !rep) {
            y++;
            rep = 1;
        }

        if (!my_char_isalphanum(str[i]) && rep)
            rep = 0;
        i++;
    }

    return (y);
}
