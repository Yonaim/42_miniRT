#include "../parse_internal.h"

bool	is_space(const char c)
{
	return (c == ' ' || c == '\t');
}

int	length_of_word(const char *line)
{
	int	len;

	len = 0;
	while (is_space(line[len]) == false && \
			get_token_type(&line[len]) == TOKEN_WORD)
		len++;
	return (len);
}
