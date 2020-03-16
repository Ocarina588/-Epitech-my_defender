/*
** EPITECH PROJECT, 2019
** task day06
** File description:
** cc
*/

char    *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (1){
        dest[i] = src[i];
        if (src[i] == '\0')
            return (dest);
        i++;
    }
}
