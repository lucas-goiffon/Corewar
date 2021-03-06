/*
** EPITECH PROJECT, 2019
** test
** File description:
** my_str_to_word_array
*/

#include "mylib.h"

int count_words_stwa_two(char const *str, char sep)
{
    int i = 0;
    int count = 0;

    while (str[i] == sep && str[i] != '\0')
        i = i + 1;
    while (str[i] != '\0') {
        if (str[i] == sep && str[i - 1] != sep)
            count = count + 1;
        i = i + 1;
    }
    if (str[i - 1] != sep)
        count = count + 1;
    return (count);
}

char *set_str_stwa_two(char const *str, int *x, char sep)
{
    int j = *x;
    int i = *x;
    char *set;

    while (str[j] != sep && str[j] != '\0')
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

char **my_str_to_word_array_two(char const *str, char sep)
{
    int nb_words = count_words_stwa_two(str, sep);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;
    char *set;

    if (array == NULL)
        return (NULL);
    while (str[i] == sep && str[i] != '\0')
        i = i + 1;
    for (int j = 0; j < nb_words; j = j + 1) {
        set = set_str_stwa_two(str, &i, sep);
        array[j] = malloc(sizeof(char) * (my_strlen(set) + 1));
        array[j] = my_strcpy(array[j], set);
        free(set);
        while (str[i] == sep && str[i] != '\0')
            i = i + 1;
    }
    array[nb_words] = NULL;
    return (array);
}