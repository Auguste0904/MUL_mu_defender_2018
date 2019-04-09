/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Game loop of my_defender
*/

#include "my.h"

void check_plant13(wallnut_t *wallnut, wallnut_t *tmp1)
{
    while (tmp1->next != NULL && tmp1->next != wallnut)
        tmp1 = tmp1->next;
    if (tmp1->next)
        tmp1->next = tmp1->next->next;
}

void check_plant10(peashooter_t *wallnut, peashooter_t *tmp1)
{
    while (tmp1->next != NULL && tmp1->next != wallnut)
        tmp1 = tmp1->next;
    if (tmp1->next)
        tmp1->next = tmp1->next->next;
}

void check_plant14(cactus_t *wallnut, cactus_t *tmp1)
{
    while (tmp1->next != NULL && tmp1->next != wallnut)
        tmp1 = tmp1->next;
    if (tmp1->next)
        tmp1->next = tmp1->next->next;
}
