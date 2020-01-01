/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** initialize_player
*/

#include "client.h"

static const int screen_multiplier = 50;

static const player_t default_player_g =
{
    &set_player_position,
    &draw_player,
    &destroy_player,
    NULL,
    {0, 0},
    0,
    -1,
    NULL
};

player_t *initialize_player(int id, sfVector2f pos,
                    sfTexture *text, sfFont *font)
{
    player_t *this = malloc(sizeof(struct player_s));
    sfVector2f size = {screen_multiplier, screen_multiplier};
    sfColor color;

    if (!this)
        return (NULL);
    memcpy(this, &default_player_g, sizeof(default_player_g));
    this->id = id;
    this->position = pos;
    this->spr = sfSprite_create();
    sfSprite_setTexture(this->spr, text, sfTrue);
    sfSprite_setPosition(this->spr, this->position);
    sfSprite_setOrigin(this->spr, size);
    this->score_txt = sfText_create();
    sfText_setFont(this->score_txt, font);
    sfText_setCharacterSize(this->score_txt, 15);
    return (this);
}

void set_player_position(struct player_s *this, sfVector2f pos)
{
    sfSprite_setPosition(this->spr, pos);
}

void draw_player(struct player_s *this, sfRenderWindow *win)
{
    char buffer[1024] = {0};
    sfVector2f center = {0, 0};
    sfVector2f text_pos = {0, 0};

    snprintf(buffer, 1024, "   %s\nScore : %d",
            this->id == -1 ? "Enemy" : "You", this->score);
    sfText_setString(this->score_txt, buffer);
    center.y = sfText_getGlobalBounds(this->score_txt).height / 2;
    center.x = sfText_getGlobalBounds(this->score_txt).width / 2;
    text_pos.x = this->position.x - 25;
    text_pos.y = this->position.y - 70;
    sfText_setOrigin(this->score_txt, center);
    sfText_setPosition(this->score_txt, text_pos);
    sfRenderWindow_drawText(win, this->score_txt, NULL);
    sfRenderWindow_drawSprite(win, this->spr, NULL);
}

void destroy_player(struct player_s *this)
{
    sfSprite_destroy(this->spr);
    free(this);
}