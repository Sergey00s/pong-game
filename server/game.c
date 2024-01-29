#include "game.h"


t_game_object *game_object(t_vec2 pos, t_vec2 vel, int width, int height)
{
	t_game_object *obj = malloc(sizeof(t_game_object));
	obj->pos = pos;
	obj->vel = vel;
	obj->width = width;
	obj->height = height;
	obj->mass = 1;
	return obj;
}

t_scene *new_scene()
{
	t_scene *scene_ = malloc(sizeof(t_scene));
	scene_->game_objects = NULL;
	return scene_;
}

void add_game_object(t_scene *scene, t_game_object *obj)
{
	list_add_back(&scene->game_objects, list_new(obj));
}

void remove_game_object(t_scene *scene, t_game_object *obj)
{
	list_remove_by_data_addr(&scene->game_objects, obj, NULL);
}



