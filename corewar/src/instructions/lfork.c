/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** lfork
*/

#include "../../include/corewar.h"

int set_cycle_lfork(info_t *info, champ_t *ch, op_t op)
{
    if (ch->save_cycle == -666)
        ch->save_cycle = info->total_cycle;
    if (ch->save_cycle != -666 &&
    ch->save_cycle + op.nbr_cycles > info->total_cycle)
        return (1);
    ch->save_cycle = -666;
    return (0);
}

void lfork_operation(info_t *info, champ_t *ch)
{
    champ_t *new = my_malloc(sizeof(champ_t));
    champ_t *save;

    new->s = ch->s;
    new->registers = my_malloc(sizeof(unsigned char *) * (REG_NUMBER + 1));
    for (int j = 0; j < REG_NUMBER; j += 1) {
        new->registers[j] = my_malloc(sizeof(unsigned char) * (REG_SIZE + 1));
        u_strcpy(new->registers[j], ch->registers[j], 4);
    }
    new->carry = ch->carry;
    new->save_cycle = ch->save_cycle;
    new->s->nb_fork += 1;
    new->pc = ch->pc + (hex_to_short(info, ch, (ch->pc + 1) % MEM_SIZE));
    if (ch->next == NULL) {
        new->next = NULL;
        ch->next = new;
    } else {
        save = ch->next;
        ch->next = new;
        new->next = save;
    }
}

int lfork_inst(info_t *info, champ_t *ch)
{
    op_t op = op_tab[14];
    int res = 0;

    if (info->memory[ch->pc] != op.code)
        return (0);
    if (set_cycle_lfork(info, ch, op) == 1)
        return (1);
    lfork_operation(info, ch);
    ch->pc += 3;
    return (1);
}