/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** animator
*/

#include "animator.h"

static const animator_t default_conf =
{
    &update_frame,
    0
};

animator_t *initialize_animator(sfTexture *text,
            float frame_offset, float framerate)
{
    animator_t *this = malloc(sizeof(animator_t));

    memcpy(this, &default_conf, sizeof(default_conf));
    this->text_sheet = text;
    this->framerate = framerate;
    this->frame_offset = frame_offset;
    this->framerate_c = sfClock_create();
    this->max_offset = sfTexture_getSize(this->text_sheet).x;
    this->current_offset = frame_offset;
}

sfIntRect update_frame(struct animator_s *this, sfSprite *spr)
{
    static float heihgt = 0;
    sfIntRect rect = {0, 0, heihgt, heihgt};
    static sfIntRect last;

    if (sfSprite_getTexture(spr) != this->text_sheet)
        return (sfSprite_getTextureRect(spr));
    if (heihgt == 0) {
        heihgt = sfTexture_getSize(this->text_sheet).y;
        last = rect;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(this->framerate_c)) <
        this->framerate ) {
        return (last);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(this->framerate_c))
                                                > this->framerate) {
        if (this->current_offset >= this->max_offset - this->frame_offset)
            this->current_offset = this->frame_offset;
        else
            this->current_offset += this->frame_offset;
        rect.left = this->current_offset;
        sfClock_restart(this->framerate_c);
        last = rect;
    }
    return (rect);
}