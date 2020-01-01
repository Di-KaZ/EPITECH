/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "run.h"

void hit_diamond(player_t player, object_t object)
{
	sfVector2f spr_pos = sfSprite_getPosition(player->sprite);
	sfVector2f obj_pos = sfSprite_getPosition(object->sprite);

	if (spr_pos.x >= obj_pos.x &&
            spr_pos.x <= obj_pos.x + (object->sprite_rect.width * 3) &&
            spr_pos.y >= obj_pos.y - 720 &&
            spr_pos.y <= obj_pos.y + 720 &&
            object->type == diamond) {
		sfMusic_play(player->sounds->gem);
		victory(player);
	}
}

void hit_jumper(player_t player, object_t object)
{
	sfVector2f spr_pos = sfSprite_getPosition(player->sprite);
	sfVector2f obj_pos = sfSprite_getPosition(object->sprite);

	if (spr_pos.x >= obj_pos.x &&
            spr_pos.x <= obj_pos.x + (object->sprite_rect.width * 3) &&
            spr_pos.y >= obj_pos.y &&
            spr_pos.y <= obj_pos.y + 20 &&
            object->type == jumper) {
		sfMusic_play(player->sounds->jumper);
		player->velo = create_vect(0, -30);
        }
}

