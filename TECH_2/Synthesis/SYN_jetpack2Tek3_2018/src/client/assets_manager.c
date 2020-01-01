/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** assets_manager
*/

#include "assets_manager.h"

static const assets_manager_t default_conf =
{
    &assets_manager_get_texture,
    &assets_manager_load_texture,
    &assets_manager_get_font,
    &assets_manager_load_font,
    &destroy_assets_manager,
    0
};

assets_manager_t *initialize_assets_manager(void)
{
    assets_manager_t *new = malloc(sizeof(assets_manager_t));

    memcpy(new, &default_conf, sizeof(default_conf));
    return (new);
}

int assets_manager_load_texture(struct assets_manager_s *this,
                                        const char *filepath)
{
    node_texture_t *temp = this->t_head;
    node_texture_t *new = NULL;

    new = create_new_node_text(filepath);
    if (!temp) {
        this->t_head = new;
        return (0);
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    return (0);
}

static sfTexture *return_if_exist(node_texture_t *t_head, const char *filepath)
{
    while (t_head) {
        if (strcmp(filepath, t_head->name) == 0)
            return (t_head->texture);
        t_head = t_head->next;
    }
    return (NULL);
}

sfTexture *assets_manager_get_texture(struct assets_manager_s *this,
                                                const char *filepath)
{
    sfTexture *return_text = return_if_exist(this->t_head, filepath);

    if (return_text)
        return (return_text);
    assets_manager_load_texture(this, filepath);
    return (return_if_exist(this->t_head, filepath));
}

void destroy_assets_manager(struct assets_manager_s *this)
{
}