/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:18:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:52 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TOKEN_BONUS_H
# define S_TOKEN_BONUS_H

enum e_token_type
{
	TOKEN_NONE,
	TOKEN_WORD,
	TOKEN_IDENTIFIER_ELEMENT,
	TOKEN_IDENTIFIER_MATERIAL,
	TOKEN_IDENTIFIER_TEXTURE,
	TOKEN_NUMBER,
	TOKEN_PIPE,
	TOKEN_COMMA,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_HASH
};

// 메타캐릭터 ",()#"를 기준으로 나누고 나머지는 다 단어(word)토큰으로 간주한다
// word 토큰 내부의 종류 identifier, number

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

#endif