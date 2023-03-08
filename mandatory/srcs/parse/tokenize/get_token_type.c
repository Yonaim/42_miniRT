/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:46:12 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 03:39:17 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal.h"

int	get_token_type(const char *str)
{
	if (*str == ',')
		return (TOKEN_COMMA);
	else if (*str == '(')
		return (TOKEN_LPAREN);
	else if (*str == ')')
		return (TOKEN_RPAREN);
	else if (*str == '|')
		return (TOKEN_PIPE);
	else if (*str == '#')
		return (TOKEN_HASH);
	else if (*str == '\0' || *str == '\n')
		return (TOKEN_NONE);
	else
		return (TOKEN_WORD);
}
