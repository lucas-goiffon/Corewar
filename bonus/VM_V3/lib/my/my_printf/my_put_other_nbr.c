/*
** EPITECH PROJECT, 2018
** my_put_other_nbr.c
** File description:
** put_nbr for my_printf project
*/

#include "my_printf.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    unsigned int result;
    static int count = 0;

    if (nb < 0) {
        nb = nb - nb - nb;
        my_putchar(45);
        count = count + 1;
    }
    result = nb % 10;
    nb = nb / 10;
    if (nb == 0) {
        my_putchar(result + 48);
        count = count + 1;
        return (count);
    }
    my_put_unsigned_nbr(nb);
    my_putchar(result + 48);
    count = count + 1;
    return (count);
}

int my_put_long_nbr(long int nb)
{
    long int result;
    static int count = 0;

    if (nb < 0) {
        nb = nb - nb - nb;
        my_putchar(45);
        count = count + 1;
    }
    result = nb % 10;
    nb = nb / 10;
    if (nb == 0) {
        my_putchar(result + 48);
        count = count + 1;
        return (count);
    }
    my_put_long_nbr(nb);
    my_putchar(result + 48);
    count = count + 1;
    return (count);
}

int my_put_pointer(void *pointer)
{
    unsigned long nb = (unsigned long) pointer;
    int count = 0;

    my_putstr("0x");
    count = hexa_conversion_low(nb);
    return (count);
}

int my_put_short_nbr(short int nb)
{
    short int result;
    static int count = 0;

    if (nb < 0) {
        nb = nb - nb - nb;
        my_putchar(45);
        count = count + 1;
    }
    result = nb % 10;
    nb = nb / 10;
    if (nb == 0) {
        my_putchar(result + 48);
        count = count + 1;
        return (count);
    }
    my_put_short_nbr(nb);
    my_putchar(result + 48);
    count = count + 1;
    return (count);
}
