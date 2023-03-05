#include "parse_internal.h"

int	get_token_type(const char *str)
{
	if (*str == ',')
		return (TOKEN_COMMA);
	else if (*str == '(')
		return (TOKEN_LPAREN);
	else if (*str == ')')
		return (TOKEN_RPAREN);
	else if (*str == '|')
		return (TOKEN_PIPE);
	else if (*str == '#')
		return (TOKEN_HASH);
	else if (*str == '\0')
		return (TOKEN_NONE);
	else
		return (TOKEN_WORD);
}