/*
** EPITECH PROJECT, 2019
** my word to str
** File description:
** in[0] :number of words
** in[1] :length of str
** in[2] :length of word
** re[0] :mark to know if we begin a word
** re[1] :mark to know in wich word we are
*/
#include <stdlib.h>
#include "my.h"

int nb_word(char *str)
{
    int nb = 0;
    int rep_space = 1;
    for (int i = 0; str[i] ; i++) {
        if (str[i] != ' ' && rep_space) {
            nb++;
            rep_space = 0;
        }
        if (str[i] == ' ')
            rep_space = 1;
    }
    return (nb);
}

char *new_word(char *str, int *index)
{
    char *word = NULL;
    int rep = 0;
    int j = 0;
    int len = 0;
    while (str[*index] == ' ')
        (*index)++;
    rep = *index;
    while (str[rep] != ' ' && str[rep])
        rep++;
    len = rep - *index;
    word = malloc(len + 1);
    if (!word)
        exit(84);
    while (str[*index] != ' ' && str[*index]) {
        word[j++] = str[(*index)++];
    }

    word[len] = 0;
    return (word);
}

char **my_str_to_word_array(char *str)
{
    char **tab = malloc(sizeof(char *) * (nb_word(str) + 1));
    if (!tab)
        exit(84);
    int index = 0;
    for (int i = 0 ; i < nb_word(str) ; i++)
        tab[i] = new_word(str, &index);
    tab[nb_word(str)] = NULL;
    return (tab);
}