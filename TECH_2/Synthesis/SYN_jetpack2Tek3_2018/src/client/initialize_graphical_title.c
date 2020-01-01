/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** initialize_graphical_title
*/

#include "client.h"

static const int screen_multiplier_g = 50;

static const title_t default_conf_g =
{
    &destroy_title,
    0
};

title_t *initialize_title(sfVector2f pos, sfTexture *text)
{
    sfVector2f size = {screen_multiplier_g, screen_multiplier_g};
    title_t *this = malloc(sizeof(title_t));

    if (!this)
        return (NULL);
    this->this = this;
    memcpy(this, &default_conf_g, sizeof(default_conf_g));
    this->spr = sfSprite_create();
    if (!this->spr)
        return (NULL);
    this->position = pos;
    sfSprite_setTexture(this->spr, text, sfTrue);
    sfSprite_setPosition(this->spr, this->position);
    return (this);
}

void destroy_title(struct title_s *this)
{
    sfSprite_destroy(this->spr);
    free(this);
    this = NULL;
}