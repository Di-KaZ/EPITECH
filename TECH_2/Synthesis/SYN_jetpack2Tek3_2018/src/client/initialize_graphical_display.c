/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** initialize_graphical_display
*/

#include "client.h"

static const int screeen_multiplier_g = 50;


static const graphic_display_t default_graphic_g =
{
    &run_graphical,
    &destroy_graphic,
    0
};

graphic_display_t *initialize_graphical(int y, int x, int id, const char **map)
{
    graphic_display_t *this = malloc(sizeof(graphic_display_t));
    sfVector2f pos = {0, 0};
    sfVideoMode mode = {1280, 500, 32};
    sfFloatRect view_rect = {0, 0, 1280, 500};

    if (!this)
        return (NULL);
    memcpy(this, &default_graphic_g, sizeof(graphic_display_t));
    this->win = sfRenderWindow_create(mode, "Jetpack2T3",
        sfTitlebar | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(this->win, 60);
    this->ass_manager = initialize_assets_manager();
    this->map = initialize_map(y, x, map, this->ass_manager);
    this->player1 = initialize_player(id, pos,
    this->ass_manager->get_texture(this->ass_manager,
                        "include/template/player.png"),
    this->ass_manager->get_font(this->ass_manager,
                        "include/template/font.ttf"));
    this->player2 = initialize_player(-1, pos,
    this->ass_manager->get_texture(this->ass_manager,
                        "include/template/player.png"),
    this->ass_manager->get_font(this->ass_manager,
                        "include/template/font.ttf"));
    this->lock = sfMutex_create();
    this->this = this;
    this->space = initialize_space_parallax(this->ass_manager);
    this->view = sfView_createFromRect(view_rect);
}

int run_graphical(struct graphic_display_s *this)
{
    sfVector2f view_pos = {0, 250};

    while (sfRenderWindow_isOpen(this->win))
    {
        while (sfRenderWindow_pollEvent(this->win, &this->event)) {
            if (this->event.type == sfEvtClosed ||
                this->event.key.code == sfKeyEscape)
                sfRenderWindow_close(this->win);
            if (this->event.type == sfEvtKeyReleased &&
                this->event.key.code == sfKeySpace) {
                if (FD_ISSET(this->client->sd, &this->readfds))
                    send_to_serv(this->client, "FIRE\n");
            }
        }
        sfRenderWindow_clear(this->win, sfBlack);
        sfView_setCenter(this->view, view_pos);
        this->space->move(this->space, this->player1->position.x - 700);
        this->space->display(this->space, this->win);
        this->map->draw(this->map, this->win);
        view_pos.x = this->player1->position.x;
        this->player1->draw(this->player1, this->win);
        this->player2->draw(this->player2, this->win);
        sfRenderWindow_display(this->win);
    }
}

void destroy_graphic(struct graphic_display_s *this)
{
    sfRenderWindow_destroy(this->win);
    this->map->destroy(this->map);
    this->player1->drestroy(this->player1);
    this->player2->drestroy(this->player2);
    this->ass_manager->destroy(this->ass_manager);
    free(this);
}