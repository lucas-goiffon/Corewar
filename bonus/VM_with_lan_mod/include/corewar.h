/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "op.h"
#include "../lib/my/mylib.h"
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>

#define SWAP_UINT32(x) ((x>>24)&0xff) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) |\
((x<<24)&0xff000000)

#define HELP "USAGE\n\
\t./corewar [-dump nbr_cycle] (-g) [[-n prog_number] [-a load_address] \
prog_name] ...\nOR if you want to play in lan:\n\
\t./corewar [-S nb_players OR -C ip_address] prog_name \n\n\
DESCRIPTION BASIC\n\
\t-g\t\tlaunch graphical interface\n\
\t-dump nbr_cycle\t\
dumps the memory after the nbr_cycle execution (if the round isn’t\n\t\t\t\
already over) with the following format: 32 bytes/line in \n\t\t\t\
hexadecimal (A0BCDEFE1DD3...)\n\t\
-n prog_number\tsets the next program’s number. By default, the first free \
number\n\t\t\t\
in the parameter order\n\t\
-a load_address\tsets the next program’s loading address. When no address is\
\n\t\t\t\
specified, optimize the addresses so that the processes are as far\n\t\t\t\
away from each other as possible. The addresses are MEM_SIZE\n\t\t\tmodulo\n\
\nDESCRIPTION LAN\n\
\t-S\t\tStart virtual machine has host and determine the number of players\n\
\t-C\t\tStart virtual machine has client\n"

#define MAX_CHAMPS 4

#define VM_CHAMP_INFO "\
Champions: [(Nb)Name]  \t[Last live] \t[Nb lives] \t[Nb forks] \t[Is alive ?]"

#define WRITE_COREWAR_1 "    \
_____                                                       "

#define WRITE_COREWAR_2 " \
__|___  |__  _____  _____   ______  __  __  __  ____    _____  "

#define WRITE_COREWAR_3 "\
|   ___|    |/     \\|     | |   ___||  \\/  \\|  ||    \\  |     | "

#define WRITE_COREWAR_4 "\
|   |__     ||     ||     \\ |   ___||     /\\   ||     \\ |     \\ "

#define WRITE_COREWAR_5 "\
|______|  __|\\_____/|__|\\__\\|______||____/  \\__||__|\\__\\|__|\\__\\"

#define WRITE_COREWAR_6 "   \
|_____|                                                      "

typedef struct stat_champ_s stat_champ_t;
struct stat_champ_s {
    char *file;
    header_t h;
    int prog_number;
    int load_address;
    int nb_live;
    int last_live;
    bool is_alive;
    int nb_fork;
};

typedef struct champ_s champ_t;
struct champ_s {
    stat_champ_t *s;
    unsigned char **registers;
    int pc;
    bool carry;
    int save_cycle;
    champ_t *next;
};

typedef struct info_s info_t;
struct info_s {
    unsigned char *memory;
    champ_t **champs;
    champ_t *last_alive;
    int dump;
    int cycle_to_die;
    int total_cycle;
    int current_cycle;
    int total_nb_live;
    int last_nb_live;
    char *colors;
    char *w_color[MAX_CHAMPS];
    bool n_curses;
    bool lan;
};

#define NORMAL   "\x1B[1;0m"
#define RED      "\x1B[1;31m"
#define GREEN    "\x1B[1;32m"
#define YELLOW   "\x1B[1;33m"
#define BLUE     "\x1B[1;34m"
#define MAGENTA  "\x1B[1;35m"
#define CYAN     "\x1B[1;36m"
#define WHITE    "\x1B[1;37m"

/* src/flags.c */
void search_for_help_flag(int ac, char **av, info_t *info);
int find_flags(int ac, char **av, info_t *info);

/* src/init_info.c */
void init_champs(champ_t *ch);
info_t *init_info(void);
void destroy_info(info_t *info);

/* src/my_exit.c */
void my_exit(info_t *info, int exit_status, char *message);

/* src/u_strcpy.c */
unsigned char *u_strcpy(unsigned char *dest, unsigned char *src, int size);

/* src/print_dump.c */
void print_hexa_values(info_t *info, unsigned char nb, char color);
void print_dump(info_t *info);

/* src/set_load_address.c */
void set_load_address(info_t *info);

/* src/read_programs.c */
void verify_extension(info_t *info, char *str);
void first_write_in_mem(info_t *info, unsigned char *to_write, int address,
champ_t *ch);
void read_program(info_t *info, int fd, champ_t *ch);
void open_programs(info_t *info);

/* src/set_first_register.c */
void set_first_register(info_t *info);

/* src/game.c */
void game(info_t *info);

/* src/conversions_hti.c */
short hex_to_short(info_t *info, champ_t *ch, int beg);
int hex_to_int(info_t *info, champ_t *ch, int beg);
int register_to_int(info_t *info, unsigned char *reg);

/* src/take_params.c */
int *take_parameters(info_t *info, champ_t *ch, op_t op);
int verify_parameters(info_t *info, champ_t *ch, op_t op, int *params);

/* src/write_in_mem.c */
void write_in_mem_regsize(info_t *info, unsigned char *to_write, int address,
champ_t *ch);
void write_in_register(info_t *info, int to_write, unsigned char *reg);

/* src/verify_pc.c */
void verify_pc(champ_t *champ);
int verify_pc_wc(int nb);

/* src/ncurses/graphic_ncurses.c */
char *get_hexa_values_ncurs(unsigned char nb, char *str);
void init_ncurses(info_t *info, WINDOW **map);
void print_map_ncurses(info_t *info, WINDOW **w);
void print_all_ncurses(info_t *info, WINDOW **w);

/* src/ncurses/ncurses_set_colors.c */
void init_ncurs_colors(info_t *info);
void set_color(info_t *info, int i, WINDOW *w);
void my_attroff(info_t *info, int i, WINDOW *w);

/* src/ncurses/actions_ncurses.c */
void pause_and_quit_ncurses(info_t *info, WINDOW **w);
void is_terminal_too_small(info_t *info);

/* src/ncurses/print_info_ncurs.c */
void print_infos_ncurses(info_t *info, WINDOW **w);

/* src/instructions/live.c */
int live_set_cycle(info_t *info, champ_t *ch, op_t op);
void live_operation(info_t *info, champ_t *ch, int i);
int live_inst(info_t *info, champ_t *ch);

/* src/instructions/zjmp.c */
int zjmp_inst(info_t *info, champ_t *ch);

/* src/instructions/sti.c */
int set_cycle_sti(info_t *info, champ_t *ch, op_t op);
void sti_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
int sti_inst(info_t *info, champ_t *ch);

/* src/instructions/and.c */
int set_cycle_and(info_t *info, champ_t *ch, op_t op);
void and_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
int set_str_and_operation(info_t *info, char *str, int param, int j);
void and_operation(info_t *info, champ_t *ch, op_t op, int *params);
int and_inst(info_t *info, champ_t *ch);

/* src/instructions/ld.c */
int set_cycle_ld(info_t *info, champ_t *ch, op_t op);
void ld_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
void ld_operation_ind(info_t *info, champ_t *ch);
void ld_operation(info_t *info, champ_t *ch, op_t op, int *params);
int ld_inst(info_t *info, champ_t *ch);

/* src/instructions/add.c */
int set_cycle_add(info_t *info, champ_t *ch, op_t op);
void add_operation(info_t *info, champ_t *ch, op_t op, int *params);
int add_inst(info_t *info, champ_t *ch);

/* src/instructions/fork.c */
int set_cycle_fork(info_t *info, champ_t *ch, op_t op);
void fork_operation(info_t *info, champ_t *ch);
int fork_inst(info_t *info, champ_t *ch);

/* src/instructions/sub.c */
int set_cycle_sub(info_t *info, champ_t *ch, op_t op);
void sub_operation(info_t *info, champ_t *ch, op_t op, int *params);
int sub_inst(info_t *info, champ_t *ch);

/* src/instructions/st.c */
int set_cycle_st(info_t *info, champ_t *ch, op_t op);
void st_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
void st_operation(info_t *info, champ_t *ch, op_t op, int *params);
int st_inst(info_t *info, champ_t *ch);

/* src/instructions/aff.c */
int set_cycle_aff(info_t *info, champ_t *ch, op_t op);
void aff_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
void aff_operation(info_t *info, champ_t *ch, op_t op, int *params);
int aff_inst(info_t *info, champ_t *ch);

/* src/instructions/or.c */
int set_cycle_or(info_t *info, champ_t *ch, op_t op);
void or_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
int set_str_or_operation(info_t *info, char *str, int param, int j);
void or_operation(info_t *info, champ_t *ch, op_t op, int *params);
int or_inst(info_t *info, champ_t *ch);

/* src/instructions/xor.c */
int set_cycle_xor(info_t *info, champ_t *ch, op_t op);
void xor_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
int set_str_xor_operation(info_t *info, char *str, int param, int j);
void xor_operation(info_t *info, champ_t *ch, op_t op, int *params);
int xor_inst(info_t *info, champ_t *ch);

/* src/instructions/lfork.c */
int set_cycle_lfork(info_t *info, champ_t *ch, op_t op);
void lfork_operation(info_t *info, champ_t *ch);
int lfork_inst(info_t *info, champ_t *ch);

/* src/instructions/lld.c */
int set_cycle_lld(info_t *info, champ_t *ch, op_t op);
void lld_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
void lld_operation_ind(info_t *info, champ_t *ch);
void lld_operation(info_t *info, champ_t *ch, op_t op, int *params);
int lld_inst(info_t *info, champ_t *ch);

/* src/instructions/ldi.c */
int set_cycle_ldi(info_t *info, champ_t *ch, op_t op);
void ldi_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
int take_param_ldi(info_t *info, champ_t *ch, int params, int *i);
void ldi_operation(info_t *info, champ_t *ch, op_t op, int *params);
int ldi_inst(info_t *info, champ_t *ch);

/* src/instructions/lldi.c */
int set_cycle_lldi(info_t *info, champ_t *ch, op_t op);
void lldi_change_pc(info_t *info, champ_t *ch, int *params, op_t op);
int take_param_lldi(info_t *info, champ_t *ch, int params, int *i);
void lldi_operation(info_t *info, champ_t *ch, op_t op, int *params);
int lldi_inst(info_t *info, champ_t *ch);

#endif /* !COREWAR_H_ */