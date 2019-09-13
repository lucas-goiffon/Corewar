/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** flags
*/

#include "../include/corewar.h"

void search_for_help_flag(int ac, char **av, info_t *info)
{
    for (int i = 1; i < ac; i = i + 1) {
        if (my_strcmp(av[i], "-h") == 0 || my_strcmp(av[i], "--help") == 0) {
            my_printf("%s", HELP);
            my_exit(info, 0, "");
        }
    }
}

void set_champs_flags(char **av, int *champ, int *i, info_t *info)
{
    int tmp = 0;
    if (my_strcmp(av[*i], "-n") == 0) {
        if (av[*i + 1] == NULL)
            my_exit(info, 84, "You must put a number after -n\n");
        tmp = my_getnbr(av[*i + 1]);
        for (int i = 0; i < MAX_CHAMPS; i = i + 1) {
            if (info->champs[i]->s->prog_number == tmp)
                my_exit(info, 84, "You can't set two same prog number\n");
        } if (tmp < 0 || tmp > MAX_CHAMPS)
            my_exit(info, 84, "Invalid champion number\n");
        info->champs[*champ]->s->prog_number = tmp;
        *i = *i + 1;
    } else if (my_strcmp(av[*i], "-a") == 0) {
        if (av[*i + 1] == NULL || my_getnbr(av[*i + 1]) < 0)
            my_exit(info, 84, "You must put a valid number after -a\n");
        info->champs[*champ]->s->load_address = my_getnbr(av[*i + 1]);
        *i = *i + 1;
    } else {
        info->champs[*champ]->s->file = av[*i];
        *champ = *champ + 1;
    }
}

int next_prog_number(info_t *info, int count)
{
    for (int j = 0; info->champs[j] != NULL; j = j + 1) {
        if (info->champs[j]->s->prog_number == count) {
            count += 1;
            j = 0;
        }
    }
    return (count);
}

void set_prog_number(info_t *info)
{
    int nb_champs = 0;
    int count = 1;

    for (nb_champs = 0; nb_champs < MAX_CHAMPS &&
    info->champs[nb_champs]->s->file != NULL; nb_champs += 1);
    if (nb_champs < 2)
        my_exit(info, 84, "You must put minimum 2 champions\n");
    count = next_prog_number(info, count);
    for (int i = 0; info->champs[i] != NULL; i = i + 1) {
        if (info->champs[i]->s->prog_number == 0) {
            info->champs[i]->s->prog_number = count;
            count = next_prog_number(info, count);
        }
    }
}

int find_flags(int ac, char **av, info_t *info)
{
    int champ = 0;
    int i = 1;

    av[ac] = NULL;
    search_for_help_flag(ac, av, info);
    if (ac > 2 && my_strcmp(av[1], "-dump") == 0) {
        if (is_digits(av[2]) != 0 || (info->dump = my_getnbr(av[2])) < 0)
            my_exit(info, 84, "Invalid nbr_cycle for dump\n");
        i += 2;
    }
    for (i = i; i < ac; i = i + 1) {
        if (my_strcmp(av[i], "-g") == 0) {
            info->n_curses = 1;
            continue;
        } if (champ > MAX_CHAMPS - 1)
            my_exit(info, 84, "We take 4 champions max\n");
        set_champs_flags(av, &champ, &i, info);
    }
    set_prog_number(info);
    return (0);
}