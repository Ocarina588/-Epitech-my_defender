/*
** EPITECH PROJECT, 2019
** capitalize
** File description:
** cc
*/

int debug(char c)
{
    if (c <= 'Z' && c >= 'A')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int rep = 0;

    while (str[i] != '\0'){
        if (str[i] <= 'Z' && str[i] >= 'A' && rep){
            str[i] += 'a' - 'A';
            rep++;
        }

        if ((str[i] <= 'z' && str[i] >= 'a') || (debug(str[i]) && !rep)){
            rep++;
            if (!debug(str[i]))
            str[i] -= 'a' - 'A';
        }

        if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
            rep = 0;
        i++;
    }
    return (str);
}
