/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** sdf
*/

#ifndef MY_H_
#define MY_H_

#define READ_SIZE (32)

#include <stdarg.h>

enum {set, get};

typedef struct flags_t {
    int tab[6];
} flags_t;

typedef struct buf_t
{
    struct buf_t *next;
    char buf[READ_SIZE];
    int len;
    int n;
    int fd;
} buf_t;

char *nbstr(int nb);
char *get_next_line(int fd);
int nb_len(int nb);
double getdouble(char *str);
void print_bool(char *bool, char *flags, int *counter);
int check_is_good_number(char *str, int i, char *flags);
int is_num(char c);
flags_t init_flags(char *str);
void move_index_bad(char *str, int *i);
void move_index(char *str, int *i);
int check_is_good_flag(char *str, int *counter);
int print(char *str, ...);
int disp_stdarg(char *s , ...);
int sum_stdarg(int i, int nb, ...);
int type_manager(char *str, va_list va);
int print_o(va_list va, char *str);
int print_s(va_list va, char *str);
int print_c(va_list va, char *str);
int print_d(va_list va, char *str);
int print_u(va_list va, char *str);
int print_x(va_list va, char *str);
int print_xm(va_list va, char *str);
int print_p(va_list va, char *str);
int print_b(va_list va, char *str);
int print_nonprintable(char c);
int print_sbig(va_list va, char *str);
int get_index(char c, char *str);
int my_putnbr_memory(long int n, int rep);
int my_putnbr_base_lowercase(unsigned int n, int base, int rep);
int my_putnbr_base_unsigned(unsigned int n, int base, int rep);
int my_putnbr_base(int n, int base, int rep);
int print_spaces(int nb, int rep);
int print_s_null(flags_t info);
int my_strlen_nonprintable(char *str);
int print_nonprintable_str(char *str);
int print_d_flags(int nb, int nb_spaces, flags_t info, int total);
int print_d_flags_zero(int nb, int nb_spaces, flags_t info);
int print_xm_flags(unsigned int nb, int nb_spaces, flags_t info);
int print_x_flags(unsigned int nb, int nb_spaces, flags_t info);
int print_p_flags_r(long int nb, int nb_spaces, flags_t info);
int print_p_flags_l(long int nb, int nb_spaces, flags_t info, int total);
int my_putchar( char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_power_it(int nb, int p);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_istrncat(char *dest, char const *src, int nb, int j);
int my_wordlen(char const *str, int i);
int my_str_words(char const *str);
int my_char_isnum(char c);
int my_char_isalphanum(char c);
int my_char_isalpha(char c);
char *concat_params(int ac, char **av);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char *str);
char *my_strdup(char const *str);
int check_good(char const *str);
int give_operator(char const *str);
int is_number(char c);
int end_retur(char const *str, int nmb);
void exchange(int *array, int i, int j);
int debug(char c);
int sum(int a, int b);
int subs(int a, int b);
int times(int a, int b);
int divid(int a, int b);
int modulo(int a, int b);

#endif
