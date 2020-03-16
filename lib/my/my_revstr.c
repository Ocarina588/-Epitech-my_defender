/*
** EPITECH PROJECT, 2019
** my revstr.c
** File description:
** cc
*/

char *my_revstr(char *str)
{
    int length = 0;
    char a;

    while (str[length] != '\0')
        length++;

    for (int i = 0; i < length ; i++){
        a = str[i];
        str[i] = str[length-1];
        str[length-1] = a;
        length--;
    }

    return (str);
}
