/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** write_in_mem
*/

#include "../include/corewar.h"

void write_in_mem_regsize(info_t *info, unsigned char *to_write, int address,
champ_t *ch)
{
    int j = 0;

    while (address < 0)
        address = MEM_SIZE + address;
    for (int i = address; i < REG_SIZE + address; i = i + 1) {
        info->memory[i % MEM_SIZE] = to_write[j];
        info->colors[i % MEM_SIZE] = ch->s->prog_number * 10 + 1;
        j = j + 1;
    }
}

void write_in_register(info_t *info, int to_write, unsigned char *reg)
{
    if (reg == NULL)
        return;
    reg[0] = (to_write >> (8 * 3));
    reg[1] = (to_write >> (8 * 2)) - (reg[0] << 8);
    reg[2] = (to_write >> (8 * 1)) - (reg[0] << (8 * 2)) - (reg[1] << 8);
    reg[3] = (to_write) - (reg[0] << (8 * 3)) -
    (reg[1] << (8 * 2)) - (reg[2] << 8);
}