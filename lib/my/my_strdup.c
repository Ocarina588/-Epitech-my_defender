/*
** EPITECH PROJECT, 2019
** mystrdup
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    char *arr = malloc ( sizeof(char) * (my_strlen(str) + 1) );
    my_strcpy(arr, str);

    return (arr);
}
