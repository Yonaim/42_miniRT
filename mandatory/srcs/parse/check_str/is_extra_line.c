#include "parse_internal.h"

/*
	(example):
	A 0.2 255,255,255
	C -50,0,20 0,0,0 70
	L -40,0,30 0.7 255,255,255
*/

bool	is_ambient_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_AMBIENT, 0, \
									format, tokens) == true);
}

bool	is_camera_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_CAMERA, 0, \
									format, tokens) == true);
}

bool	is_light_line(const t_token_arr *tokens)
{
	const int	format[] = {
		TOKEN_IDENTIFIER_ELEMENT,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NUMBER,
		TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER, TOKEN_COMMA, TOKEN_NUMBER,
		TOKEN_NONE
	};

	return (is_valid_formatted_line(IDENTIFIER_ELEMENT_LIGHT, 0, \
									format, tokens) == true);
}
