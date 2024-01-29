#include <stdio.h>
#include <stdlib.h>
#include "game.h"


int main(int argc, char const *argv[])
{
	t_scene *scene_;
	t_game_object *ball = game_object(vec2(0, 150), vec2(1, 0), 10, 10);
	scene_ = new_scene();
	add_game_object(scene_, ball);
	printf("scene size: %zu\n", list_size(scene_->game_objects));
	printf("ball pos: %f, %f\n", ball->pos.x, ball->pos.y);
	printf("ball vel: %f, %f\n", ball->vel.x, ball->vel.y);
	remove_game_object(scene_, ball);
	return 0;
}
