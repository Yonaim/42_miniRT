#include "parse_internal.h"

static int	count_tokens(const char *line)
{
	int	cnt;
	int	type;
	int	str_len;

	cnt = 0;
	while (*line)
	{
		while (is_space(*line) == true)
			line++;
		type = get_token_type(line);
		if (type == TOKEN_NONE)
			break ;
		else if (type == TOKEN_WORD)
			str_len = length_of_word(line);
		else
			str_len = 1;
		line += str_len;
		cnt++;
	}
	return (cnt);
}

static int	extract_word_token(t_token *token, char **line)
{
	const int	len = length_of_word(*line);

	token->type = TOKEN_WORD;
	token->str = ft_substr(*line, 0, len);
	if (token->str == NULL)
		return (FAILURE);
	*line += len;
	return (SUCCESS);
}

static void	extract_non_word_token(t_token *token, char **line, int token_type)
{
	token->type = token_type;
	token->str = NULL;
	*line += 1;
}

static int	extract_tokens(char *line, t_token *tokens, int token_cnt)
{
	int	type;
	int	i;

	i = 0;
	while (i < token_cnt)
	{
		while (is_space(*line) == true)
			line++;
		type = get_token_type(line);
		if (type == TOKEN_NONE)
			break ;
		else if (type == TOKEN_WORD)
		{
			if (extract_word_token(&tokens[i], &line) == FAILURE)
				return (FAILURE);
		}
		else
			extract_non_word_token(&tokens[i], &line, type);
		i++;
	}
	tokens[token_cnt].type = TOKEN_NONE;
	return (SUCCESS);
}

int	determine_word_tokens_type(t_token *tokens, int token_cnt)
{
	int	i;

	while (i < token_cnt)
	{
		if (tokens[i].type == TOKEN_WORD)
		{
			if (is_number_str(tokens[i].str))
				tokens[i].type = TOKEN_NUMBER;
			else if (is_identifier_str(tokens[i].str))
				tokens[i].type = TOKEN_IDENTIFIER;
			else
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

t_token	*tokenize(char *line)
{
	t_token	*tokens;
	int		token_cnt;

	token_cnt = count_tokens(line);
	tokens = malloc(sizeof(t_token) * (token_cnt + 1));
	if (tokens == NULL)
		return (NULL);
	if (extract_tokens(line, tokens, token_cnt) == FAILURE)
		return (NULL);
	if (determine_word_tokens_type(tokens, token_cnt) == FAILURE)
		return (NULL);
	return (tokens);
}

int main()
{
	// t_token *tokens = tokenize("aa bb cc  ,#,,");
	// int i = 0;
	// while (tokens[i].type != TOKEN_NONE)
	// {
	// 	printf("token type: %d ", tokens[i].type);
	// 	printf("token str: %s\n", tokens[i].str);
	// 	i++;
	// }
}