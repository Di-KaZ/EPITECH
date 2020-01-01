/*
** EPITECH PROJECT, 2018
**
** File description:
** 
*/

#include "run.h"

void (*hit_obj[4])(player_t player, object_t object) =
{
	hit_lava,
	hit_heart,
	hit_jumper,
	hit_diamond
};

void hit_heart (player_t player, object_t object)
{
	sfVector2f spr_pos = sfSprite_getPosition(player->sprite);
	sfVector2f obj_pos = sfSprite_getPosition(object->sprite);

	if (spr_pos.x >= obj_pos.x &&
	    spr_pos.x <= obj_pos.x + (object->sprite_rect.width * 4) &&
	    spr_pos.y >= obj_pos.y - 32 &&
	    spr_pos.y <= obj_pos.y + 100 &&
	    object->type == heart &&
	    player->life != 3) {
		sfMusic_play(player->sounds->heart);
		player->life += 1;
		player->life_rect.left -= 80;
		object->sprite_rect = create_rect(0, 0, 0, 0);
	}

}

void hit_lava(player_t player, object_t object)
{
	sfVector2f spr_pos = sfSprite_getPosition(player->sprite);
	sfVector2f obj_pos = sfSprite_getPosition(object->sprite);

	if (spr_pos.x >= obj_pos.x &&
	    spr_pos.x <= obj_pos.x + (object->sprite_rect.width * 3) &&
	    spr_pos.y >= obj_pos.y &&
	    spr_pos.y <= obj_pos.y + 32 &&
	    object->type == lava && get_elapsed_time(player->hitable) > 2.0) {
		sfMusic_play(player->sounds->damage);
		player->hit = 1;
	}
}

int plateforme (player_t player, object_t object)
{
	sfVector2f spr_pos = {0 ,0};
	sfVector2f obj_pos = {0, 0};
	int return_val = 0;

	while (object != NULL) {
		spr_pos = sfSprite_getPosition(player->sprite);
		obj_pos = sfSprite_getPosition(object->sprite);
		hit_lava(player, object);
		hit_heart(player, object);
		hit_jumper(player, object);
		hit_diamond(player, object);
		if (spr_pos.x >= obj_pos.x &&
		    spr_pos.x <= obj_pos.x + (object->sprite_rect.width * 3) + 20
		    && spr_pos.y >= obj_pos.y &&
		    spr_pos.y <= obj_pos.y + 15 &&
		    object->type == plat1) {
			return_val = 1;
		}
		object = object->next;
	}
	return(return_val);
}

void ground (player_t player, object_t object)
{
	if (plateforme (player, object) == 0
	    && sfSprite_getPosition(player->sprite).y + 1 <= 610)
		player->on_ground = 0;
	else
		player->on_ground = 1;
}

void apply_gravity(player_t player, object_t list)
{
	if (get_elapsed_time(player->game_speed) > 0.01) {
		if (player->velo.y < 15)
			player->velo.y += 1;
		ground (player, list);
		if (player->on_ground == 0)
			sfSprite_move(player->sprite, player->velo);
		sfClock_restart(player->game_speed->clock);
	}
}
