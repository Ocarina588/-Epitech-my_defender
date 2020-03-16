/*
** EPITECH PROJECT, 2019
** square root
** File description:
** cc
*/

int    my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 1)
        return (0);

    while ( (i * i) != nb )
    {
        if ( (i * i) > nb )
            return (0);

        i++;
    }

    return (i);
}
