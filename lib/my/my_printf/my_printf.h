/*
** EPITECH PROJECT, 2019
** MyGit
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include "../mylib.h"
#include <stdarg.h>

int option_printf(char const *format, int *z, va_list ap, ...);
int my_printf(char const *format, ...);
int s_low_flag(char const *format, int *i, va_list ap);
int d_and_i_flags(char const *format, int *i, va_list ap);
int u_flag(char const *format, int *i, va_list ap);
int ld_flag(char const *format, int *i, va_list ap);
int c_flag(char const *format, int *i, va_list ap);
int p_flag(char const *format, int *i, va_list ap);
int x_low_flag(char const *format, int *i, va_list ap);
int x_upp_flag(char const *format, int *i, va_list ap);
int b_flag(char const *format, int *i, va_list ap);
int o_flag(char const *format, int *i, va_list ap);
int s_upp_call_flag(char const *format, int *i, va_list ap);
int mod_flag(char const *format, int *i, va_list ap);
int b_flag(char const *format, int *i, va_list ap);
int s_upp_flag(char *str);
int binary_conversion(unsigned long nb);
void binary_conversion_two(int r, char *str, int char_size);
int hexa_conversion_upp(unsigned long nb);
void hexa_conversion_upp_two(int r, char *str, int char_size);
int hexa_conversion_low(unsigned long nb);
void hexa_conversion_low_two(int r, char *str, int char_size);
int octal_conversion(unsigned long nb);
void octal_conversion_two(int r, char *str, int char_size);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_long_nbr(long int nb);
int my_put_pointer(void *pointer);
int nbsign_flag(char const *format, int *i, va_list ap);
int nbsign_flag_two(char const *format, int *i, va_list ap);
int spaces_delete_printf(char const *format, int *i, va_list ap);
int my_put_short_nbr(short int nb);
int hd_flag(char const *format, int *i, va_list ap);
int octal_conversion_s_upp(unsigned long nb);

#endif /* !MY_PRINTF_H_ */
