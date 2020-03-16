/*
** EPITECH PROJECT, 2019
** concat params
** File description:
** sdkjf
*/

#include <stdlib.h>
#include "my.h"

char *concat_params(int ac, char **av)
{
    int len = 0;
    char *str;

    for (int i = 0 ; i < ac ; i++) {

        len = len + my_strlen(av[i]);
        len++;
    }

    str = malloc( sizeof(char) * len );

    for (int i = 0 ; i < ac ; i++) {
        str = my_strcat(str, av[i]);
        str = my_strcat(str, "\n");
    }

    return (str);
}
