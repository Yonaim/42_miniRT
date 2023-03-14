/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:08:25 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:08:26 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_internal_bonus.h"

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
	free(tokens->data);
	free(tokens);
}
