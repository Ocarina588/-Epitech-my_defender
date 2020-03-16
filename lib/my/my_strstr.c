/*
** EPITECH PROJECT, 2019
** mystrstr
** File description:
** cc
*/
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int count = 0;
    char *first;

    while (to_find[j] != '\0')
        j++;

    for (int i = 0 ; str[i] != '\0' ; i++){
        if (str[i] != to_find[count])
            count = 0;
        if (str[i] == to_find[count]){
            if (!count)
                first = str + i;
            count++;
            if (count == j)
                return (first);
        }
    }
    return (NULL);
}