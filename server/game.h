#ifndef __GAME_H__
# define __GAME_H__

#include "vector.h"
#include <llist.h>


typedef struct	s_game_object
{
	t_vec2 pos;
	t_vec2 vel;
	int width;
	int height;
	float mass;
	//momentum = mass * velocity
}				t_game_object;


typedef struct s_scene
{
	t_list 		*game_objects;

}				t_scene;

// game object operations


// scene operations


t_game_object 	*game_object(t_vec2 pos, t_vec2 vel, int width, int height);
t_scene			*new_scene();
void			add_game_object(t_scene *scene, t_game_object *obj);
void            remove_game_object(t_scene *scene, t_game_object *obj);
#endif