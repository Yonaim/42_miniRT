
#include "parse_internal.h"
#include <string.h>

// 해쉬(#) 문자 이후로는 주석으로 취급
bool	is_valid_formatted_line(char *identifier, \
								int *form, t_token_arr *tokens)
{
	t_token	*token;
	int		i;

	if (strcmp(identifier, ((t_token *)tokens->data[i])->str) != 0)
		return (false);
	i = 0;
	while (i < tokens->cnt)
	{
		token = (t_token *)tokens->data[i];
		if (token->type == TOKEN_HASH)
			break ;
		if (token->type != form[i])
			return (false);
		i++;
	}
	if (form[i] != TOKEN_NONE)
		return (false);
	return (true);
}