/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/07 18:46:12 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal_bonus.h"

bool	is_space(const char c)
{
	return (c == ' ' || c == '\t');
}

int	length_of_word(const char *line)
{
	int	len;

	len = 0;
	while (is_space(line[len]) == false \
			&& line[len] != '\n' \
			&& get_token_type(&line[len]) == TOKEN_WORD)
		len++;
	return (len);
}
