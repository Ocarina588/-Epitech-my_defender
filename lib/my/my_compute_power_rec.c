/*
** EPITECH PROJECT, 2019
** computer rec
** File description:
** cc
*/

int    my_compute_power_rec(int nb, int p)
{
    if (!p)
        return (1);
    if (p<0)
        return (0);

    return (nb * my_compute_power_rec(nb, p-1));
}
