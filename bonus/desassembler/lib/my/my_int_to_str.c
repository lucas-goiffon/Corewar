/*
** EPITECH PROJECT, 2018
** my_int_to_str.c
** File description:
** Put an int into an str
*/

#include "mylib.h"

char *my_int_to_str_neg(int nb)
{
    int count = 0;
    int test = nb * -1;
    char *str;

    nb = nb * -1;
    while (test > 0) {
        count++;
        test = test / 10;
    }
    if ((str = malloc(sizeof(char) * (count + 2))) == NULL)
        return (NULL);
    str[count + 1] = '\0';
    my_strcpy(str, "-");
    count--;
    while (count >= 0) {
        test = nb % 10;
        str[count + 1] = test + 48;
        nb = nb / 10;
        count--;
    } return (str);
}

char *my_int_to_str(int nb)
{
    int count = 0;
    int test = nb;
    char *str;

    if (nb < 0)
        return (my_int_to_str_neg(nb));
    while (test > 0) {
        count++;
        test = test / 10;
    } if ((str = malloc(sizeof(char) * (count + 2))) == NULL)
        return (NULL);
    str[count] = '\0';
    my_strcpy(str, "0");
    count--;
    while (count >= 0) {
        test = nb % 10;
        str[count] = test + 48;
        nb = nb / 10;
        count--;
    } return (str);
}