#include "parse_internal.h"

t_info		*get_info_ambient(const t_token_arr *tokens);
t_info		*get_info_camera(const t_token_arr *tokens);
t_info		*get_info_light(const t_token_arr *tokens);
t_info		*get_info_plane(const t_token_arr *tokens);
t_info		*get_info_sphere(const t_token_arr *tokens);
t_info		*get_info_cylinder(const t_token_arr *tokens);
t_info		*get_info_cone(const t_token_arr *tokens);
t_info		*get_info_box(const t_token_arr *tokens);

/*
	(example):
	A 0.2 255,255,255
	C -50,0,20 0,0,0 70
	L -40,0,30 0.7 255,255,255
	
	Solid element의 경우, '<element> <고유 정보> [material] [texture]'
	ex) sp 0,0,20 20 l s 255,0,0
*/

// t_info		*get_info_ambient(const t_token_arr *tokens)
// {
// 	t_info_ambient_light	info;
// 	t_token					*token;
	
// 	info.brightness
// }