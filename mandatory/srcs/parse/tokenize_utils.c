#include "parse_internal.h"

bool	is_space(const char c)
{
	return (c == ' ' || c == '\t');
}

int	get_token_type(const char *input)
{
	if (*input == ',')
		return (TOKEN_COMMA);
	else if (*input == '(')
		return (TOKEN_LPAREN);
	else if (*input == ')')
		return (TOKEN_RPAREN);
	else if (*input == '#')
		return (TOKEN_HASH);
	else if (*input == '\0')
		return (TOKEN_NONE);
	else
		return (TOKEN_WORD);
}

int	length_of_word(const char *line)
{
	int	len;

	len = 0;
	while (is_space(line[len]) == false && \
			get_token_type(&line[len]) == TOKEN_WORD)
		len++;
	return (len);
}
