/*
** EPITECH PROJECT, 2019
** power it
** File description:
** cc
*/

int    my_compute_power_it(int nb, int p)
{
    if (!p)
        return (1);
    if (p<0)
        return (0);

    int multi = nb;
    nb = 1;

    for (int i = 0; i < p ; i++)
        nb *= multi;

    return (nb);
}
