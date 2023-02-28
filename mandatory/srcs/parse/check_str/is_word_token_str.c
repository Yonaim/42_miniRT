#include "../parse_internal.h"
#include <stdbool.h>


bool	is_number_str(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (ft_isdigit(*s) == false)
		return (false);
	while (ft_isdigit(*s) == true)
		s++;
	if (*s == '.')
	{
		s++;
		if (ft_isdigit(*s) == false)
			return (false);
		while (ft_isdigit(*s) == true)
			s++;
	}
	if (*s == '\0')
		return (true);
	return (false);
}
