/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_formatted_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:19 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

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

static bool	is_valid_formatted_object_line(const t_token_arr *tokens, \
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
		return (is_valid_material(tokens, i));
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
	if (ft_strcmp(elem_id, (nth_token(tokens, 0)->str)) != 0)
		return (false);
	if (is_solid_elem)
		return (is_valid_formatted_object_line(tokens, \
											form, length_of_format(form)));
	else
		return (is_valid_formatted_extra_line(tokens, \
											form, length_of_format(form)));
}
