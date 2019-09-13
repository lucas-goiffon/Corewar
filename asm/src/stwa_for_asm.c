/*
** EPITECH PROJECT, 2019
** test
** File description:
** stwa_for_asm
*/

#include "../include/asm.h"

int count_words_stwa_asm(char const *str)
{
    int i = 0;
    int count = 0;

    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        i = i + 1;
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == C) &&
        str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != C)
            count = count + 1;
        i = i + 1;
    }
    if (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != C)
        count = count + 1;
    if (i == 0)
        count = count + 1;
    return (count);
}

char *set_str_stwa_asm(char const *str, int *x)
{
    int j = *x;
    int i = *x;
    char *set;

    while (str[j] != ' ' && str[j] != '\t' && str[j] != C && str[j] != '\0')
        j = j + 1;
    set = malloc(sizeof(char) * (j - i + 1));
    fill_str(set, j - i + 1);
    for (int v = 0; i < j; v = v + 1) {
        set[v] = str[i];
        i = i + 1;
    }
    *x = i;
    return (set);
}

char **stwa_asm(char const *str)
{
    int nb_words = count_words_stwa_asm(str);
    char **array = my_malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;
    char *set;

    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        i = i + 1;
    if (str[i] == '\0') {
        array[0] = my_malloc(sizeof(char) * 1);
        array[0][0] = '\0';
        return (array);
    } for (int j = 0; j < nb_words; j = j + 1) {
        set = set_str_stwa_asm(str, &i);
        array[j] = malloc(sizeof(char) * (my_strlen(set) + 1));
        array[j] = my_strcpy(array[j], set);
        free(set);
        while ((str[i] == ' ' || str[i] == '\t' || str[i] == C)
        && str[i] != '\0')
            i = i + 1;
    } array[nb_words] = NULL;
    return (array);
}