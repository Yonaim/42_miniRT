#include "parse_internal.h"

/*
	(example):
	A 0.2 255,255,255
	C -50,0,20 0,0,0 70
	L -40,0,30 0.7 255,255,255
*/

bool	is_ambient_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_AMBIENT, \
									tokens, format) == true);
}

bool	is_camera_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_CAMERA, \
									tokens, format) == true);
}

bool	is_light_line(t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_formatted_line(IDENTIFIER_ELEMENT_LIGHT, \
									tokens, format) == true);
}
