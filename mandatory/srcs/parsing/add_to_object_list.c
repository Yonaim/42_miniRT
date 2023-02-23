#include "parsing_internel.h"

int	add_to_object_list(t_list **object_list, t_object *new_object)
{
	t_list	*new;

	if (!new_object)
		return (FAILURE);
	new = ft_lstnew(new_object);
	if (!new)
		return (FAILURE);
	ft_lstadd_back(object_list, new);
	return (SUCCESS);
}