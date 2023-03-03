/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:43:44 by yona              #+#    #+#             */
/*   Updated: 2023/03/01 11:41:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer_internal.h"

void	destroy_token_arr(t_token *token_arr)
{
	int	i;

	if (!token_arr)
		return ;
	i = 0;
	while (token_arr[i].type != TOKEN_NONE)
	{
		if (token_arr[i].type == TOKEN_NUMBER \
			|| token_arr[i].type == TOKEN_WORD)
			free(token_arr[i].str);
		i++;
	}
	free(token_arr);
}
