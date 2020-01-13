#include "my_cook.h"
static object_t add_ing_to_list (ingredient_t *to_add, scene_t play)
{
	object_t mdr = NULL;

	if (aleready_exist(play->objs, to_add->name))
		return (play->objs);
	mdr = malloc(sizeof(*mdr));
	if (!mdr)
		return (play->objs);
	mdr->name = to_add->name;
	mdr->type = to_add->flag | FOOD;
	mdr->sprite = ini_sprite(to_add->path);
	mdr->offset = sfSprite_getLocalBounds(mdr->sprite->sprite).width / 3;
	food_status (mdr);
	mdr->next = play->objs;
	return (mdr);
}

static int check_is_in_box (ingredient_t *object, sfVector2f mouse_pos)
{
	sfFloatRect rect;

	if (!object)
		return(0);
	rect = sfSprite_getLocalBounds(object->sprite->sprite);
	if (mouse_pos.x < sfSprite_getPosition(object->sprite->sprite).x +
		rect.width &&
		mouse_pos.x > sfSprite_getPosition(object->sprite->sprite).x &&
		mouse_pos.y < sfSprite_getPosition(object->sprite->sprite).y +
		rect.height &&
		mouse_pos.y > sfSprite_getPosition(object->sprite->sprite).y)
                return (1);
        return (0);
}

static void manage_changing_ing (game_t game, ingredient_t *to_disp)
{
	if (!sfRenderWindow_pollEvent(game->window->window, &game->window->event))
		return;
	scene_t play = find_scene(game->scenes, "play");
	if (!to_disp || game->ing_pos < 0)
		game->ing_pos = 0;
	if (game->window->event.key.code == sfKeyLeft &&
	    game->window->event.type == sfEvtKeyReleased && game->ing_pos != 0)
		game->ing_pos -= 1;
	if (game->window->event.key.code == sfKeyRight &&
	    game->window->event.type == sfEvtKeyReleased) {
		game->ing_pos += 1;
	}
	if (check_is_in_box(to_disp, get_mouse_pos(game->window)) &&
		game->window->event.type == sfEvtMouseButtonReleased)
			play->objs =
			add_ing_to_list(to_disp, play);
}

static ingredient_t *move_to (ingredient_t *ingredients, int go)
{
	ingredient_t *to_return = ingredients;

	for (int i = 0; i != go; i += 1) {
		if (to_return)
			to_return = to_return->next;
	}
	return (to_return);
}

void disp_ingredients_menu (game_t game)
{
	static ingredient_t *to_display = NULL;

	manage_changing_ing(game, to_display);
	to_display = move_to(game->ingredients, game->ing_pos);
	if (!to_display) {
		game->ing_pos = 0;
		to_display = move_to(game->ingredients, game->ing_pos);
	}
	sfSprite_setPosition(to_display->sprite->sprite,
		create_vect(100, 900));
	sfRenderWindow_drawSprite(game->window->window,
		to_display->sprite->sprite, NULL);
}
