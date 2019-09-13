/*
** EPITECH PROJECT, 2018
** pointerarray.h
** File description:
** Declaration of an array of pointer on functions
*/

#ifndef POINTERARRAY_H_
#define POINTERARRAY_H_

#define array                                                           \
int (*pointer_on_function[15])(char const *, int *, va_list) =          \
{nbsign_flag, spaces_delete_printf, s_low_flag, d_and_i_flags,          \
    u_flag, ld_flag, c_flag, p_flag, x_low_flag, x_upp_flag, b_flag,    \
    hd_flag, o_flag, s_upp_call_flag, mod_flag}

#endif
