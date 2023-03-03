#include "parse_internal.h"

t_info		*get_info_ambient(t_token_arr *tokens);
t_info		*get_info_camera(t_token_arr *tokens);
t_info		*get_info_light(t_token_arr *tokens);
t_info		*get_info_plane(t_token_arr *tokens);
t_info		*get_info_sphere(t_token_arr *tokens);
t_info		*get_info_cylinder(t_token_arr *tokens);
t_info		*get_info_cone(t_token_arr *tokens);
t_info		*get_info_box(t_token_arr *tokens);

/*
	(example):
	A 0.2 255,255,255
	C -50,0,20 0,0,0 70
	L -40,0,30 0.7 255,255,255
*/

t_info		*get_info_ambient(t_token_arr *tokens)
{
	t_info_ambient_light	info;
	t_token					*token;
	
	info.brightness
}