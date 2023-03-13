#include "../parse_internal.h"

void	destroy_token_arr(t_token_arr *tokens)
{
	t_token	*token;
	int		i;

	i = 0;
	while (i < tokens->cnt)
	{
		token = (t_token *)tokens->data[i];
		free(token->str);
		free(token);
		i++;
	}
	free(tokens);
}