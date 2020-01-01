/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** parallax_layer
*/

#include "parallax_layer.h"

static const parallax_layer_t default_conf =
{
    &move_parallax_layer,
    &display_parallax_layer,
    0
};

static const space_parallax_t default_space_conf =
{
    &move_space_parallax,
    &display_space_parallax,
    0
};

parallax_layer_t *initialize_parallax_layer(sfTexture *text)
{
    parallax_layer_t *this = malloc(sizeof(parallax_layer_t));
    sfVector2f pos;

    memcpy(this, &default_conf, sizeof(default_conf));
    this->first = sfSprite_create();
    this->second = sfSprite_create();
    sfSprite_setTexture(this->first, text, sfTrue);
    sfSprite_setTexture(this->second, text, sfTrue);
    pos.x = -sfSprite_getGlobalBounds(this->first).width / 2;
    sfSprite_setPosition(this->first, pos);
    this->temp = NULL;
}

void move_parallax_layer(struct parallax_layer_s *this,
                        float speed, float reset_pos)
{
    sfVector2f pos = sfSprite_getPosition(this->first);
    sfVector2f move_speed = {speed, 0};

    pos.x += sfSprite_getGlobalBounds(this->first).width;
    sfSprite_setPosition(this->second, pos);
    sfSprite_move(this->first, move_speed);
    if (sfSprite_getPosition(this->first).x +
        sfSprite_getGlobalBounds(this->first).width <= reset_pos) {
            this->temp = this->first;
            this->first = this->second;
            this->second = this->temp;
    }
}

void display_parallax_layer(struct parallax_layer_s *this, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, this->first, NULL);
    sfRenderWindow_drawSprite(win, this->second, NULL);
}

space_parallax_t *initialize_space_parallax(assets_manager_t *manager)
{
    space_parallax_t *spaaaace = malloc(sizeof(space_parallax_t));

    memcpy(spaaaace, &default_space_conf, sizeof(default_space_conf));
    spaaaace->one = initialize_parallax_layer
    (manager->get_texture(manager, "include/template/layers/bg.png"));
    spaaaace->two = initialize_parallax_layer
    (manager->get_texture(manager, "include/template/layers/1.png"));
    spaaaace->three = initialize_parallax_layer
    (manager->get_texture(manager, "include/template/layers/2.png"));
    spaaaace->four = initialize_parallax_layer
    (manager->get_texture(manager, "include/template/layers/3.png"));
    spaaaace->five = initialize_parallax_layer
    (manager->get_texture(manager, "include/template/layers/4.png"));
}

void move_space_parallax(struct space_parallax_s *spaaace,
                                            float reset_pos)
{
    spaaace->one->move(spaaace->one, -0.1, reset_pos);
    spaaace->two->move(spaaace->two, -0.2, reset_pos);
    spaaace->three->move(spaaace->three, -0.3, reset_pos);
    spaaace->four->move(spaaace->four, -0.4, reset_pos);
    spaaace->five->move(spaaace->five, -0.5, reset_pos);
}