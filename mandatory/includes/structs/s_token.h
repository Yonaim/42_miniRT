#ifndef S_TOKEN_H
# define S_TOKEN_H

enum	e_token_type
{
	TOKEN_WORD,
	TOKEN_NUMBER,
	TOKEN_COMMA,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_HASH,
	TOKEN_NONE
};

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

#endif