/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include "../../include/op.h"
#include "../../lib/my/mylib.h"
#include <fcntl.h>
#include <unistd.h>

#define SWAP_UINT32(x) ((x>>24)&0xff) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) |\
((x<<24)&0xff000000)

#define C SEPARATOR_CHAR

typedef struct stock_t stock_t;
struct stock_t
{
    short int is_label;
    short int *size;
    int *to_write;
};

typedef struct element_t element_t;
struct element_t
{
    char **array;
    stock_t *stock;
    int op;
    element_t *next;
    element_t *prev;
};

typedef struct list_t list_t;
struct list_t
{
    element_t *first;
    element_t *last;
    int lenght;
    char *file_name;
};

typedef struct info_t info_t;
struct info_t
{
    list_t *list;
    struct header_s header;
    stock_t **stock;
};

/* src/main.c */
int error_management(int ac, char **av);
int read_file(char *av, list_t *list);
void destroy_all(info_t *info);

/* src/linked_lists.c */
element_t *insertion_end(list_t *list, char *str);
void print_list(list_t *list);
void destroy_ll(list_t *list);
list_t *initialisation_empty(void);
void delete_middle(list_t *list, element_t *to_delete);

/* src/stwa_for_asm.c */
int count_words_stwa_asm(char const *str);
char *set_str_stwa_asm(char const *str, int *x);
char **stwa_asm(char const *str);

/* src/header.c */
char *remove_double_quotes(info_t *info, char *str);
int set_header_name(info_t *info, header_t *head);
int set_header_comment(info_t *info, header_t *head);
int set_header(info_t *info, header_t *head);

/* src/stock.c */
int understanding_file(info_t *info);
void init_stock(info_t *info);
void calcul_prog_size(info_t *info);
void destroy_stock(info_t *info);

/* src/my_exit.c */
void my_exit(info_t *info, int exit_status);

/* src/get_parameters.c */
int get_param_type(char *str);
int get_param_size(element_t *e, char *str);

/* src/mnemonics.c */
void verify_parameters(element_t *e, info_t *info, stock_t *stock, int op);
int get_inside_parameter(char *str, info_t *info);
void stock_parameters(element_t *e, info_t *info);
int find_mnemonics(element_t *e, info_t *info, int k);

/* src/manage_indexs.c */
int add_size_element(info_t *info, element_t *a);
void stock_count_index(info_t *info, element_t *s, int count, int i);
void find_corresponding_label_reverse(info_t *info, element_t *s, char *str,
int i);

/* src/write_in_file.c */
void write_in(info_t *info, element_t *a, int i, int fd);
char *name_of_file(info_t *info);
void write_all(info_t *info);

/* src/call_labels.c */
int is_index(info_t *info, char *str, int j, element_t *actual);
char *remove_label_char(info_t *info, element_t *s, int i);
int cmp_label_and_index(info_t *info, element_t *a, char *str);
void find_corresponding_label(info_t *info, element_t *a, int i);
void call_labels(info_t *info);

/* src/badchars_labels.c */
int verify_badchars(element_t *actual);
int badchars_labels(info_t *info);

/* src/is_same_labels.c */
int is_same_labels(info_t *info);

#endif /* !ASM_H_ */