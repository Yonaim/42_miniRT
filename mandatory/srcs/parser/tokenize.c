#include "parser.h"

static int	count_tokens(const char *line)
{
	int	cnt;
	int	type;
	int	str_len;

	cnt = 0;
	while (*line)
	{
		skip_spaces(&line);
		type = get_token_type(line);
		if (type == TOKEN_NONE)
			break ;
		else if (type == TOKEN_NUMBER)
			str_len = length_of_number(line);
		else if (type == TOKEN_WORD)
			str_len = length_of_word(line);
		else
			str_len = 1;
		line += str_len;
		cnt++;
	}
	return (cnt);
}

static int	extract_tokens(char *line, t_token *token_arr, int token_cnt)
{
	int	type;
	int	str_len;
	int	i;

	i = 0;
	while (i < token_cnt)
	{
		skip_spaces(&line);
		type = get_token_type(line);
		if (type == TOKEN_NUMBER)
			str_len = length_of_number(*line);
		else if (type == TOKEN_WORD)
			str_len = length_of_word(*line);
		else
			str_len = 1;
		token_arr[i].type = type;
		token_arr[i].str = ft_substr(*line, 0, str_len);
		if (token_arr[i].str == NULL)
			return (FAILURE);
		line += str_len;
		i++;
	}
	token_arr[token_cnt].type = TOKEN_NONE;
	return (SUCCESS);
}

t_token	*tokenize(char *line)
{
	t_token	*token_arr;
	int		token_cnt;

	token_cnt = count_tokens(line);
	token_arr = malloc(sizeof(t_token) * (token_cnt + 1));
	if (token_arr == NULL)
		return (NULL);
	if (extract_tokens(line, token_arr, token_cnt) == FAILURE)
		return (NULL);
	return (token_arr);
}
