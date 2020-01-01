/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** initialize_graphical_map
*/

#include "client.h"

static const int screen_multiplier_g = 50;

static const map_t default_conf_g =
{
    &draw_map,
    &destroy_map,
    0
};

static title_t ***create_map(int y, int x,
        const char **map_str, assets_manager_t *manager)
{
    title_t ***map = malloc(sizeof(title_t **) * (x + 1));
    sfVector2f pos = {0, 0};
    sfColor none = {0, 0, 0, 0};
    int i = 0;
    int j = 0;

    if (!map)
        return (NULL);
    for (i = 0; map_str[i]; i += 1) {
        map[i] = malloc(sizeof(title_t *) * (y + 1));
        if (!map[i])
            return (NULL);
        for (j = 0; map_str[i][j]; j += 1) {
            pos.x = j * screen_multiplier_g;
            pos.y = i * screen_multiplier_g;
            if (map_str[i][j] == 'c')
                map[i][j] = initialize_title(pos,
                        manager->get_texture(manager,
                            "include/template/anim_coin.png"));
            if (map_str[i][j] == 'e')
                map[i][j] = initialize_title(pos,
                        manager->get_texture(manager,
                            "include/template/brick_block.png"));
            if (map_str[i][j] == '_')
                map[i][j] = initialize_title(pos, NULL);
        }
        map[i][j] = NULL;
    }
    map[i] = NULL;
    return (map);
}

map_t *initialize_map(int x, int y,
    const char **map, assets_manager_t *manager)
{
    map_t *this = malloc(sizeof(struct map_s));

    if (!this)
        return (NULL);
    memcpy(this, &default_conf_g, sizeof(default_conf_g));
    this->this = this;
    this->max_x = x;
    this->max_y = y;
    this->title_map = create_map(x, y, map, manager);
    this->coin_anim = initialize_animator(
    manager->get_texture(manager, "include/template/anim_coin.png"), 50, 0.2);
    return (this);
}

void draw_map(map_t *this, sfRenderWindow *win)
{
    for (int y = 0;this->title_map[y]; y += 1) {
        for (int x = 0;this->title_map[y][x]; x += 1) {
            sfSprite_setTextureRect(this->title_map[y][x]->spr,
            this->coin_anim->update_frame(this->coin_anim,
            this->title_map[y][x]->spr));
            sfRenderWindow_drawSprite(win,
                    this->title_map[y][x]->spr, NULL);
        }
    }
}

void destroy_map(map_t *this)
{
    for (int y = 0;this->title_map[y]; y += 1) {
        for (int x = 0; this->title_map[x][y]; x += 1) {
            this->title_map[y][x]->destroy
                    (this->title_map[y][x]->this);
        }
    }
    free (this);
}