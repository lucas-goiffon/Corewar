/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** read_programs
*/

#include "../include/corewar.h"

void verify_extension(info_t *info, char *str)
{
    char *n_str = str;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '.') {
            str = &str[i];
            i = 0;
        }
    }
    if (my_strcmp(str, ".cor") != 0)
        my_exit(info, 84, "Wrong file extension. It must be a .cor file\n");
}

void first_write_in_mem(info_t *info, unsigned char *to_write, int address,
champ_t *ch)
{
    int j = 0;
    int size = ch->s->h.prog_size;

    if (address + size >= MEM_SIZE)
        my_exit(info, 84, "Program is out of the memory\n");
    for (int i = address; i < size + address; i = i + 1) {
        if (info->memory[i] != 0)
            my_exit(info, 84, "Program is walking on another\n");
        info->memory[i] = to_write[j];
        info->colors[i] = ch->s->prog_number * 10;
        j = j + 1;
    }
}

void read_program(info_t *info, int fd, champ_t *ch)
{
    unsigned char *champ = NULL;

    read(fd, &ch->s->h, sizeof(header_t));
    ch->s->h.magic = SWAP_UINT32(ch->s->h.magic);
    ch->s->h.prog_size = SWAP_UINT32(ch->s->h.prog_size);
    if (ch->s->h.magic != COREWAR_EXEC_MAGIC)
        my_exit(info, 84, "Bad MAGIC\n");
    champ = my_malloc(sizeof(unsigned char) * (ch->s->h.prog_size + 1));
    read(fd, champ, ch->s->h.prog_size);
    first_write_in_mem(info, champ, ch->s->load_address, ch);
    free(champ);
}

void open_programs(info_t *info)
{
    int fd = -1;

    for (int i = 0; i < MAX_CHAMPS && info->champs[i]->s->file != NULL;
    i += 1) {
        verify_extension(info, info->champs[i]->s->file);
        fd = open(info->champs[i]->s->file, O_RDONLY);
        if (fd < 0)
            my_exit(info, 84, "Unable to open a champion\n");
        read_program(info, fd, info->champs[i]);
        close(fd);
    }
}