/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** node_font
*/

#include "assets_manager.h"

node_font_t *create_new_node_font(const char *font_name)
{
    node_font_t *new = malloc(sizeof(node_font_t));

    new->font = sfFont_createFromFile(font_name);
    new->next = NULL;
    new->name = strdup(font_name);
}

void destroy_node_font(node_font_t *this)
{
}

int assets_manager_load_font(struct assets_manager_s *this,
                                        const char *filepath)
{
    node_font_t *temp = this->f_head;
    node_font_t *new = NULL;

    new = create_new_node_font(filepath);
    if (!temp) {
        this->f_head = new;
        return (0);
    }
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    return (0);
}

static sfFont *return_if_exist(node_font_t *f_head, const char *filepath)
{
    while (f_head) {
        if (strcmp(filepath, f_head->name) == 0)
            return (f_head->font);
        f_head = f_head->next;
    }
    return (NULL);
}

sfFont *assets_manager_get_font(struct assets_manager_s *this,
                                                const char *filepath)
{
    sfFont *return_text = return_if_exist(this->f_head, filepath);

    if (return_text)
        return (return_text);
    assets_manager_load_font(this, filepath);
    return (return_if_exist(this->f_head, filepath));
}