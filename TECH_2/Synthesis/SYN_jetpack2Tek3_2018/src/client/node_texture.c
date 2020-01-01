/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** node_texture
*/

#include "assets_manager.h"
#include "parallax_layer.h"

node_texture_t *create_new_node_text(const char *text_name)
{
    node_texture_t *new = malloc(sizeof(node_texture_t));

    new->name = strdup(text_name);
    new->texture = sfTexture_createFromFile(new->name, NULL);
    new->next = NULL;
}


void display_space_parallax(struct space_parallax_s *spaace,
                                        sfRenderWindow *win)
{
    spaace->one->display(spaace->one, win);
    spaace->two->display(spaace->two, win);
    spaace->three->display(spaace->three, win);
    spaace->four->display(spaace->four, win);
    spaace->five->display(spaace->five, win);
}

void destroy_node_text(node_texture_t *this)
{

}