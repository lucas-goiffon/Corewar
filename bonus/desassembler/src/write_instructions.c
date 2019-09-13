/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** write_instructions
*/

#include "../include/desassembler.h"

int write_parameters(desasm_t *des, int i, int op, int param)
{
    char *nbr;
    if (param == 1) {
        write(des->fd, "r", 1);
        nbr = my_int_to_str(des->bytes[i]);
        write(des->fd, nbr, my_strlen(nbr));
        i += 1;
    } else if (param == 2 && op != 8 && op != 9 && op != 10 && op != 11 &&
    op != 13 && op != 14) {
        nbr = my_int_to_str(hex_to_int(des, i));
        write(des->fd, "%", 1);
        write(des->fd, nbr, my_strlen(nbr));
        i += DIR_SIZE;
    } else {
        nbr = my_int_to_str((int)hex_to_short(des, i));
        if (param == 2)
            write(des->fd, "%", 1);
        write(des->fd, nbr, my_strlen(nbr));
        i += IND_SIZE;
    } free(nbr);
    return (i);
}

int with_coding_byte(desasm_t *des, int i, int op)
{
    int *params = take_parameters(des->bytes[i]);

    i += 1;
    for (int k = 0; k < op_tab[op].nbr_args; k += 1) {
        i = write_parameters(des, i, op, params[k]);
        if (k + 1 < op_tab[op].nbr_args)
            write(des->fd, ", ", 2);
    }
    free(params);
    return (i);
}

int without_coding_byte(desasm_t *des, int i, int op)
{
    char *nbr;

    write(des->fd, "%", 1);
    if (op == 0) {
        nbr = my_int_to_str(hex_to_int(des, i));
        write(des->fd, nbr, my_strlen(nbr));
        i += DIR_SIZE;
    } else {
        nbr = my_int_to_str((int)hex_to_short(des, i));
        write(des->fd, nbr, my_strlen(nbr));
        i += IND_SIZE;
    }
    free(nbr);
    return (i);
}

void write_instructions(desasm_t *des)
{
    int i = 0;

    while (i < des->h.prog_size) {
        write(des->fd, "\t", 1);
        write(des->fd, op_tab[des->bytes[i] - 1].mnemonique,
        my_strlen(op_tab[des->bytes[i] - 1].mnemonique));
        write(des->fd, " ", 1);
        if (des->bytes[i] != 1 && des->bytes[i] != 9 && des->bytes[i] != 12
        && des->bytes[i] != 15)
            i = with_coding_byte(des, i + 1, des->bytes[i] - 1);
        else
            i = without_coding_byte(des, i + 1, des->bytes[i] - 1);
        write(des->fd, "\n", 1);
    }
}