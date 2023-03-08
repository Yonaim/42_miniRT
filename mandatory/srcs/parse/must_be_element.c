#include "parse_internal.h"

bool	is_must_be_one_element_type(int type)
{
	const int	must_be_one[] = {
		ELEMENT_AMBIENT,
		ELEMENT_CAMERA,
		ELEMENT_NONE
	};
	int			i;

	i = 0;
	while (must_be_one[i] != ELEMENT_NONE)
	{
		if (type == must_be_one[i])
			return (true);
		i++;
	}
	return (false);
}

bool	is_must_be_elements_exist(bool elem_exist[])
{
	int	i;

	i = 0;
	while (i < ELEMENT_TYPE_COUNT)
	{
		if (is_must_be_one_element_type(i) == true \
			&& elem_exist[i] == 0)
			return (false);
		i++;
	}
	return (true);
}
