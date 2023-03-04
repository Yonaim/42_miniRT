
#include "parse_internal.h"
#include <string.h>

t_token	*nth_token(t_token_arr *tokens, int nth)
{
	t_token *token;

	token = (t_token *)tokens->data[nth];
	return (token);
}

static bool	is_valid_material_specified(t_token_arr *tokens, int offset)
{
	if (nth_token(tokens, offset)->type != TOKEN_IDENTIFIER_MATERIAL)
		return (false);
	if (tokens->cnt >= offset)
	{
		if (nth_token(tokens, offset + 1)->type != TOKEN_IDENTIFIER_TEXTURE)
			return (false);
		if (nth_token(tokens, offset + 2)->type != TOKEN_LPAREN \
			|| nth_token(tokens, offset + 3)->type != TOKEN_NUMBER
			|| nth_token(tokens, offset + 4)->type != TOKEN_COMMA
			|| nth_token(tokens, offset + 5)->type != TOKEN_NUMBER
			|| nth_token(tokens, offset + 6)->type != TOKEN_COMMA
			|| nth_token(tokens, offset + 7)->type != TOKEN_NUMBER
			|| nth_token(tokens, offset + 8)->type != TOKEN_RPAREN)
			return (false);
		if (nth_token(tokens, offset + 8)->type != TOKEN_NONE)
			return (false);
	}
	else
		return (true);
}

bool	is_valid_formatted_line(char *elem_id, bool is_solid_elem, \
									int *form, t_token_arr *tokens)
{
	int	i;

	if (strcmp(elem_id, (nth_token(tokens, 0)->str) != 0))
		return (false);
	i = 0;
	while (i < tokens->cnt && form[i] != TOKEN_NONE)
	{
		// if (token->type == TOKEN_HASH)
		// 	break ;
			// TO DO: 해쉬(#) 문자 이후로는 주석으로 취급
		if (nth_token(tokens, i)->type != form[i])
			return (false);
		i++;
	}
	if (i < tokens->cnt)
	{
		if (is_solid_elem) 
			return (is_valid_material_specified(tokens, i));
		else
			return (false);
	}
	return (true);
}

// extra - TOKEN_NONE이면 true
// solid - TOKEN_NONE이거나 혹은 MATERIAL이 나오면 true