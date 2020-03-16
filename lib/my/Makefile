##
## EPITECH PROJECT, 2019
## makefile
## File description:
## sdf
##

SRC	=	concat_params.c	\
		my_sort_int_array.c	\
		my_strlen.c	\
		my_isneg.c	\
		my_strcapitalize.c	\
		my_strlowcase.c	\
		my_strcat.c	\
		my_strncat.c	\
		my_char_isalpha.c	\
		my_istrncat.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_char_isalphanum.c	\
		my_putchar.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_char_isnum.c	\
		my_put_nbr.c	\
		my_strdup.c	\
		my_strstr.c	\
		my_compute_power_it.c	\
		my_putstr.c	\
		my_str_isalpha.c	\
		my_str_to_word_array.c	\
		my_compute_power_rec.c	\
		my_revstr.c	\
		my_str_islower.c	\
		my_strupcase.c	\
		my_compute_square_root.c	\
		my_str_isnum.c	\
		my_str_words.c	\
		my_str_isprintable.c	\
		my_swap.c	\
		my_getnbr.c	\
		my_show_word_array.c	\
		my_str_isupper.c	\
		my_wordlen.c	\
		my_putnbr_base.c	\
		my_printf.c	\
		my_printf_function.c	\
		my_printf_function_two.c	\
		my_printf_functionthree.c	\
		my_printf_functionfor.c	\
		my_printf_function_five.c	\
		flags_function.c	\
		getfloat.c	\
		get_next_line.c

OBJ     =       $(SRC:.c=.o)

NAME	=	libmy.a

HEADER	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp $(HEADER) ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
