#include "parse_internal.h"

/*
	(example):
	pl 0,0,0 0,1.0,0 255,0,225
	sp 0,0,20 20 255,0,0
	cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
	cn 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
	bo 30,0,0 0,20,10 255,255,255
*/

bool	is_plane_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_PLANE, \
									tokens, format) == true);
}

bool	is_sphere_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_SPHERE, \
									tokens, format) == true);
}

bool	is_cylinder_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_CYLINDER, \
									tokens, format) == true);
}

bool	is_cone_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_CONE, \
									tokens, format) == true);
}

bool	is_box_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_BOX, \
									tokens, format) == true);
}