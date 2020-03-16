/*
** EPITECH PROJECT, 2020
** button func
** File description:
** sdf
*/

#include "my.h"
#include "defense.h"
#include "button.h"

init_button_func_t relative(char *name)
{
    button_t button = update_init_button(0, button, 0);

    my_strcpy(button.relative, name);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t name(char *name)
{
    button_t button = update_init_button(0, button, 0);

    my_strcpy(button.entity.name, name);

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t on_click(void (*func)(void *, ...))
{
    button_t button = update_init_button(0, button, 0);

    button.click = func;

    update_init_button(1, button, 0);

    return (get_func_button());
}

init_button_func_t function(void (*func)(void *, ...))
{
    button_t button = update_init_button(0, button, 0);

    button.function = func;

    update_init_button(1, button, 0);
    return (get_func_button());
}

init_button_func_t multiple(void (*normal)(void *, ...),
    void (*hover)(void *, ...), void (*click)(void *, ...),
    void (*function)(void *, ...))
{
    button_t button = update_init_button(0, button, 0);

    button.normal = normal;
    button.hover = hover;
    button.click = click;
    button.function = function;

    update_init_button(1, button, 0);

    return (get_func_button());
}
