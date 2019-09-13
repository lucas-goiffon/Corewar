/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** desassembler
*/

#ifndef DESASSEMBLER_H_
#define DESASSEMBLER_H_

#include "../lib/my/mylib.h"
#include "op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <unistd.h>

#define SWAP_UINT32(x) ((x>>24)&0xff) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) |\
((x<<24)&0xff000000)

typedef struct desasm_s desasm_t;
struct desasm_s {
    unsigned char *bytes;
    header_t h;
    int fd;
};

/* src/read_create_file.c */
int open_and_read_file(desasm_t *des, char *file);
int create_file(desasm_t *des, char *old_file);

/* src/write_instrctuons.c */
int write_parameters(desasm_t *des, int i, int op, int param);
int with_coding_byte(desasm_t *des, int i, int op);
int without_coding_byte(desasm_t *des, int i, int op);
void write_instructions(desasm_t *des);

/* src/tools.c */
int *take_parameters(unsigned char c);
short hex_to_short(desasm_t *des, int beg);
int hex_to_int(desasm_t *des, int beg);

#endif /* !DESASSEMBLER_H_ */