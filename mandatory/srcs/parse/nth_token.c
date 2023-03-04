#include "parse_internal.h"

t_token	*nth_token(const t_token_arr *tokens, int nth)
{
	t_token *token;

	token = (t_token *)tokens->data[nth];
	return (token);
}
