
#include "../parse_internal.h"
#include <string.h>

static bool	is_valid_material_specified(const t_token_arr *tokens, int offset)
{
	if (!(nth_token(tokens, offset)->type == TOKEN_PIPE \
		&& (tokens->cnt == offset + 8 || tokens->cnt == offset + 10)))
		return (false);
	if (nth_token(tokens, offset + 1)->type == TOKEN_LPAREN \
		&& nth_token(tokens, offset + 2)->type == TOKEN_NUMBER
		&& nth_token(tokens, offset + 3)->type == TOKEN_COMMA
		&& nth_token(tokens, offset + 4)->type == TOKEN_NUMBER
		&& nth_token(tokens, offset + 5)->type == TOKEN_COMMA
		&& nth_token(tokens, offset + 6)->type == TOKEN_NUMBER
		&& nth_token(tokens, offset + 7)->type == TOKEN_RPAREN)
		return (true);
	else if (nth_token(tokens, offset + 1)->type == TOKEN_IDENTIFIER_MATERIAL \
		&& nth_token(tokens, offset + 2)->type == TOKEN_IDENTIFIER_TEXTURE
		&& nth_token(tokens, offset + 3)->type == TOKEN_LPAREN
		&& nth_token(tokens, offset + 4)->type == TOKEN_NUMBER
		&& nth_token(tokens, offset + 5)->type == TOKEN_COMMA
		&& nth_token(tokens, offset + 6)->type == TOKEN_NUMBER
		&& nth_token(tokens, offset + 7)->type == TOKEN_COMMA
		&& nth_token(tokens, offset + 8)->type == TOKEN_NUMBER
		&& nth_token(tokens, offset + 9)->type == TOKEN_RPAREN)
		return (true);
	return (false);
}

static bool	is_valid_formatted_extra_line(const t_token_arr *tokens, \
										const int *form, const int form_len)
{
	int	i;

	i = 0;
	if (tokens->cnt != form_len)
		return (false);
	while (form[i] != TOKEN_NONE)
	{
		if (nth_token(tokens, i)->type != form[i])
			return (false);
		i++;
	}
	return (true);
}

static bool	is_valid_formatted_solid_line(const t_token_arr *tokens, \
										const int *form, const int form_len)
{
	int	i;

	i = 0;
	if (tokens->cnt < form_len)
		return (false);
	while (form[i] != TOKEN_NONE)
	{
		if (nth_token(tokens, i)->type != form[i])
			return (false);
		i++;
	}
	if (tokens->cnt == form_len)
		return (true);
	else
		return (is_valid_material_specified(tokens, i));
}

int	length_of_format(const int *form)
{
	int	len;
	
	len = 0;
	while (form[len] != TOKEN_NONE)
		len++;
	return (len);
}

bool	is_valid_formatted_line(const char *elem_id, bool is_solid_elem, \
									const t_token_arr *tokens, const int *form)
{
	if (strcmp(elem_id, (nth_token(tokens, 0)->str)) != 0)
		return (false);
	if (is_solid_elem)
		return (is_valid_formatted_solid_line(tokens, \
											form, length_of_format(form)));
	else
		return (is_valid_formatted_extra_line(tokens, \
											form, length_of_format(form)));
}
