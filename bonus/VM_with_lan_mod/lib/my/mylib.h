/*
** EPITECH PROJECT, 2018
** mylib.h
** File description:
** Task02 of CPool Day09
*/

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stdlib.h>
#include "my_printf/my_printf.h"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_nbr_error(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prind_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *concat_params(int argc, char **argv);
char *my_int_to_str(int nb);
void fill_str(char *str, int size);
void fill_str_two(char *str, int size, char to_replace);
char *my_strcat_two(char *dest, char const *src);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_two(char const *str, char sep);
char *get_next_line(int fd);
char *my_strcat_for_gnl(char *dest, char const *src);
int my_strlen_for_gnl(char const *str);
void fill_str_gnl(char *str, int size, char to_replace);
void destroy_double_array(char **array);
int is_digits(char *str);
int is_alpha(char *str);
void *my_malloc(size_t size);
int my_tablen(char **array);
void print_double_array(char **array);
int my_strcmp_maj(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
void *my_memset(void *dest, int c, size_t n);
void *my_realloc(void *dest, size_t n);
void *my_memcpy(void *dest, void *src, size_t n);

#endif
