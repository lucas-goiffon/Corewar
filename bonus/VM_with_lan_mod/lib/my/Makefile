##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make for libmy.a.
##

SRC_PRINTF  =   my_printf/my_printf.c               \
                my_printf/my_put_other_nbr.c        \
                my_printf/conversions.c             \
                my_printf/conversions_two.c         \
                my_printf/s_upp_flag.c              \
                my_printf/s_low_flag.c              \
                my_printf/d_and_i_flags.c           \
                my_printf/u_flag.c                  \
                my_printf/ld_flag.c                 \
                my_printf/c_flag.c                  \
                my_printf/p_flag.c                  \
                my_printf/x_low_flag.c              \
                my_printf/x_upp_flag.c              \
                my_printf/b_flag.c                  \
                my_printf/o_flag.c                  \
                my_printf/s_upp_call_flag.c         \
                my_printf/mod_flag.c				\
				my_printf/nbsign_flag.c			    \
				my_printf/spaces_delete_printf.c	\
				my_printf/hd_flag.c

SRC		=		concat_params.c                     \
                my_putchar.c                        \
                my_strncpy.c                        \
                my_put_nbr.c                        \
                my_put_nbr_error.c                  \
                my_strcat.c                         \
                my_strstr.c                         \
                my_compute_power_rec.c              \
                my_putstr.c                         \
                my_putstr_error.c                   \
                my_strcmp.c                         \
                my_revstr.c                         \
                my_strcpy.c                         \
                my_strlen.c                         \
                my_swap.c                           \
                my_getnbr.c                         \
                my_strdup.c                         \
                my_isneg.c                          \
                my_strncat.c                        \
				my_int_to_str.c                     \
                fill_str.c                          \
                my_strcat_two.c                     \
                my_str_to_word_array.c              \
                my_str_to_word_array_two.c          \
                fill_str_two.c                      \
                get_next_line.c                     \
                destroy_double_array.c              \
                is_digits.c                         \
                is_alpha.c                          \
                my_malloc.c                         \
                my_tablen.c                         \
                print_double_array.c                \
                my_strcmp_maj.c                     \
                $(SRC_PRINTF)                       \
                my_memset.c                         \
                my_realloc.c                        \
                my_memcpy.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

all:	$(NAME) clean

$(NAME):		$(OBJ)
		ar rc $(NAME) *.o my_printf/*.o

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all clean

auteur:
		echo $(USER) > LuCas
