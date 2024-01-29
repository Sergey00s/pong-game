#include "vector.h"

t_vec2 vec2(float x, float y)
{
	t_vec2 v;
	v.x = x;
	v.y = y;
	return v;
}

t_vec2 vec2_add(t_vec2 a, t_vec2 b)
{
	return vec2(a.x + b.x, a.y + b.y);
}

t_vec2 vec2_sub(t_vec2 a, t_vec2 b)
{
	return vec2(a.x - b.x, a.y - b.y);
}

t_vec2 vec2_mul(t_vec2 a, float b)
{
	return vec2(a.x * b, a.y * b);
}


