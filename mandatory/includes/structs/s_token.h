#ifndef S_TOKEN_H
# define S_TOKEN_H

enum e_token_type
{
	TOKEN_NONE,
	TOKEN_WORD,
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
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