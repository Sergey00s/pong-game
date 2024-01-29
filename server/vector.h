#ifndef __VECTOR_H__
# define __VECTOR_H__

#include <math.h>


typedef struct	s_vec2
{
	float x;
	float y;
}				t_vec2;


t_vec2			vec2(float x, float y);
t_vec2			vec2_add(t_vec2 a, t_vec2 b);
t_vec2			vec2_sub(t_vec2 a, t_vec2 b);
t_vec2 			vec2_mul(t_vec2 a, float b);



#endif