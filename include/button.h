/*
** EPITECH PROJECT, 2020
** button h
** File description:
** sdf
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Keyboard.h>
#include "essentile.h"

typedef struct init_button_func_t
{
    struct init_button_func_t (*coord)(int, int);
    struct init_button_func_t (*size)(int, int);
    struct init_button_func_t (*sprite)(button_selector);
    struct init_button_func_t (*name)(char *);
    struct init_button_func_t (*relative)(char *);
    struct init_button_func_t (*function)(void (*func)(void *, ...));
    struct init_button_func_t (*normal)(void (*func)(void *, ...));
    struct init_button_func_t (*hover)(void (*func)(void *, ...));
    struct init_button_func_t (*color)(sfColor);
    struct init_button_func_t (*interval)(int, int, size_t);
    struct init_button_func_t (*on_click)(void (*func)(void *, ...));
    struct init_button_func_t (*multiple)(void (*normal)(void *, ...),
        void (*hover)(void *, ...), void (*click)(void *, ...),
        void (*function)(void *, ...));
    struct init_button_func_t (*rotation)(float);

} init_button_func_t;

init_button_func_t size(int x, int y);
init_button_func_t coord(int x, int y);
init_button_func_t name(char *name);
init_button_func_t relative(char *name);
init_button_func_t color(sfColor color);
init_button_func_t interval(int a, int b, size_t offset);
init_button_func_t sprite(button_selector i);
init_button_func_t normal(void (*func)(void *, ...));
init_button_func_t hover(void (*func)(void *, ...));
init_button_func_t get_func_button(void);
init_button_func_t on_click(void (*func)(void *, ...));
init_button_func_t function(void (*func)(void *, ...));
init_button_func_t rotation(float a);
init_button_func_t multiple(void (*normal)(void *, ...),
    void (*hover)(void *, ...), void (*click)(void *, ...),
    void (*function)(void *, ...));
button_t update_init_button(int mode, button_t button, scene_selector i);
init_button_func_t new_button(scene_selector scene);

#endif
