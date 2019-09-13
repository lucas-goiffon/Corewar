/*
** EPITECH PROJECT, 2019
** CoreWar
** File description:
** header
*/

#include "../include/asm.h"

char *remove_double_quotes(info_t *info, char *str)
{
    int i = 0;

    if (str[0] == 34)
        str = &str[1];
    i = my_strlen(str) - 1;
    if (str[i] != 34 && str[i] != ' ' && str[i] != '\t')
        my_exit(info, 84);
    str[i] = '\0';
    return (str);
}

int set_header_name(info_t *info, header_t *head)
{
    element_t *actual = info->list->first;
    char *str;
    int ok = 0;

    if (actual == NULL)
        return (84);
    if (my_strcmp(actual->array[0], NAME_CMD_STRING) == 0 &&
    actual->array[1] != NULL)
        ok = 1;
    if (ok == 0)
        return (84);
    if (actual->array[1][0] == '\0' || actual->array[1][0] != '\"')
        return (84);
    str = remove_double_quotes(info, actual->array[1]);
    if (my_strlen(str) > PROG_NAME_LENGTH)
        return (84);
    my_strcpy(head->prog_name, str);
    return (0);
}

int set_header_comment(info_t *info, header_t *head)
{
    element_t *actual = info->list->first;
    char *str;
    int ok = 0;

    if (actual == NULL)
        return (0);
    if (my_strcmp(actual->array[0], COMMENT_CMD_STRING) == 0 &&
    actual->array[1] != NULL)
        ok = 1;
    if (ok == 0)
        return (1);
    if (actual->array[1][0] == '\0' || actual->array[1][0] != '\"')
        return (84);
    str = remove_double_quotes(info, actual->array[1]);
    if (my_strlen(str) > COMMENT_LENGTH)
        return (84);
    my_strcpy(head->comment, str);
    return (0);
}

int set_header(info_t *info, header_t *head)
{
    int is_comment = 0;

    head->magic = COREWAR_EXEC_MAGIC;
    head->magic = SWAP_UINT32(info->header.magic);
    if (set_header_name(info, head) == 84)
        return (84);
    delete_middle(info->list, info->list->first);
    if ((is_comment = set_header_comment(info, head)) == 84)
        return (84);
    info->header.prog_size = 0;
    if (is_comment != 1)
        delete_middle(info->list, info->list->first);
    return (0);
}