#include "my_hunter.h"

title_t *ini_title (void)
{
	title_t *title = malloc(sizeof(*title));
	title->title = ini_sprite("Ressources/titlescreen_none.png");
	title->title_play = ini_sprite("Ressources/titlescreen_play.png");
	title->title_quit = ini_sprite("Ressources/titlescreen_quit.png");
	return(title);
}
void free_title(title_t **title)
{
	destroy_sprite(&(*title)->title);
	destroy_sprite(&(*title)->title_play);
	destroy_sprite(&(*title)->title_quit);
	free(*title);
}
