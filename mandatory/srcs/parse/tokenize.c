#include "parse_internal.h"

static t_token	*extract_word_token(char **line)
{
	t_token		*token;
	const int	len = length_of_word(*line);

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = TOKEN_WORD;
	token->str = ft_substr(*line, 0, len);
	if (!token->str)
		return (NULL);
	*line += len;
	return (token);
}

static t_token	*extract_non_word_token(char **line, int token_type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = token_type;
	token->str = NULL;
	*line += 1;
	return (token);
}

static int	extract_tokens(char *line, t_token_arr *tokens)
{
	t_token	*token;
	int		type;

	while (*line)
	{
		while (is_space(*line) == true)
			line++;
		type = get_token_type(line);
		if (type == TOKEN_NONE)
			break ;
		else if (type == TOKEN_WORD)
			token = extract_word_token(&line);
		else
			token = extract_non_word_token(&line, type);
		push_back_dynamic_arr(tokens, (void *)token);
	}
	return (SUCCESS);
}

static int	match_word_tokens_type(t_token_arr *tokens)
{
	t_token	*token;
	int		i;

	i = 0;
	while (i < tokens->cnt)
	{
		token = (t_token *)tokens->data[i];
		if (token->type == TOKEN_WORD)
		{
			if (is_number_str(token->str) == true)
				token->type = TOKEN_NUMBER;
			else if (get_element_type(token->str) != -1)
				token->type = TOKEN_IDENTIFIER_ELEMENT;
			else if (get_material_type(token->str) != -1)
				token->type = TOKEN_IDENTIFIER_MATERIAL;
			else if (get_texture_type(token->str) != -1)
				token->type = TOKEN_IDENTIFIER_TEXTURE;
			else
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

t_token_arr	*tokenize(char *line)
{
	t_token_arr	*tokens;

	tokens = new_dynamic_arr(INITIAL_OBJECT_ARR_SIZE);
	if ((extract_tokens(line, tokens) == FAILURE
		|| match_word_tokens_type(tokens) == FAILURE))
	{
		destroy_dynamic_arr(tokens);
		return (NULL);
	}
	return (tokens);
}
