#include "parse_internal.h"
#include <stdbool.h>

bool	is_identifier_str(char *s)
{
	const t_get_identifier_type	get_identifier_type_func[] = {
	get_element_type,
	get_material_type,
	get_texture_type,
	NULL
	};
	int							i;

	i = 0;
	while (get_identifier_type_func[i])
	{
		if (get_identifier_type_func[i](s) != -1)
			return (true);
		i++;
	}
	return (false);
}

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
		s++;
	if (ft_isdigit(*s) == false)
		return (false);
	while (ft_isdigit(*s) == true)
		s++;
	if (*s == '\0')
		return (true);
	return (false);
}
