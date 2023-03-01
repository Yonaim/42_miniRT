#include "parser.h"

int	get_token_type(const char *input)
{
	if ('0' <= *input && *input <= '9')
		return (TOKEN_NUMBER);
	else if (*input == ',')
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
	while (get_token_type(&line[len]) == TOKEN_WORD)
		len++;
	return (len);
}

int	length_of_number(const char *line)
{
	int	len;

	len = 0;
	while (get_token_type(&line[len]) == TOKEN_NUMBER)
		len++;
	return (len);
}
