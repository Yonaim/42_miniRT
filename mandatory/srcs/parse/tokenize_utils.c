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

// 소수 10.4
// 부호 붙은 수 +123 혹은 -223
// int	length_of_number(const char *line)
// {
// 	int	len;
// 	bool is_point_exist;

// 	is_point_exist = false;
// 	len = 0;
// 	if (line[0] == '+' || line[0] == '-')
// 		len++;
// 	while ('0' <= line[len] && line[len] <= '9')
// 	{
// 		len++;
// 		if (line[len] == '.')
// 		{
// 			if (is_point_exist == true)
// 				return (-1);
// 			is_point_exist = 1;
// 			len++;
// 		}
// 	}
// 	return (len);
// }
