/*
** EPITECH PROJECT, 2019
** derniere task
** File description:
** cc
*/

void    exchange(int *array, int i, int j)
{
    int item;

    if ( *(array + i) > *(array + j) )
    {
        item = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = item;
    }
}

void    my_sort_int_array(int *array, int size)
{
    for ( int i = 0 ; i < size - 1 ; i++ )
        for ( int j = i ; j < size ; j++ )
            exchange(array , i , j);
}
