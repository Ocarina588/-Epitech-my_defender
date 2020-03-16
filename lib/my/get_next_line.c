/*
** EPITECH PROJECT, 2019
** get next line
** File description:
** sdf
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

char *push(char *str, char *buffer)
{
    char *new_str;
    int len = -1;

    if (!str)
        return (NULL);
    while (str[++len]);
    new_str = malloc(len + 2);
    if (!new_str)
        return (NULL);
    for (int i = 0; str[i] ; i++)
        new_str[i] = str[i];
    new_str[len] = *buffer;
    new_str[len + 1] = 0;
    free(str);
    for (int i = 0; READ_SIZE == 1 ? i < 1 : i < READ_SIZE - 1 ; i++) {
        buffer[i] = buffer[READ_SIZE > 1 ? i + 1 : 0];
        buffer[READ_SIZE > 1 ? i + 1 : 0] = 0;
    }
    return (new_str);
}

char *gnl(int fd, buf_t *buf)
{
    char *str = malloc(1);

    if (fd < 0 || !str)
        return (NULL);
    *str = 0;
    while (1) {
        if (buf->n || (!*(buf->buf) &&
            (buf->len = read(fd, (buf->buf), READ_SIZE)) < 1))
            break;
        for (int i = 0; str && *(buf->buf) &&
            !(buf->n = *(buf->buf) == '\n'); i++)
            str = push(str, (buf->buf));
        for (int i = 0; buf->n &&
            READ_SIZE < 2 ? i < 1 : i < READ_SIZE - 1; i++) {
            (buf->buf)[i] = (buf->buf)[READ_SIZE > 1 ? i + 1 : 0];
            (buf->buf)[READ_SIZE > 1 ? i + 1 : 0] = 0;
        }
    }
    return (!str || (!*str && !buf->n) ? NULL : str);
}

buf_t *init_buf(int fd)
{
    buf_t *buf = malloc(sizeof(buf_t));

    if (!buf)
        return (NULL);
    buf->fd = fd;
    buf->len = READ_SIZE;
    buf->n = 0;
    buf->next = NULL;

    for (int i = 0; i < READ_SIZE ; i++)
        buf->buf[i] = 0;

    return (buf);
}

char *get_next_line(int fd)
{
    static buf_t *buf = NULL;
    buf_t *tmp;
    if (fd < 0 || !(buf = buf ? buf : init_buf(fd)))
        return (NULL);
    tmp = buf;
    while (tmp) {
        if (tmp->fd == fd)
            break;
        tmp = tmp->next;
    }
    if (tmp) {
        tmp->n = 0;
        return (gnl(fd, tmp));
    }
    tmp = buf;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = init_buf(fd);
    return (tmp->next ? gnl(fd, tmp->next) : NULL);
}