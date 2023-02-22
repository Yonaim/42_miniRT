
#include "ft_printf_internal.h"

t_node	*fmt_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	fmt_lstallclear(t_node *const startnode)
{
	t_node			*curr;
	t_node			*next;

	curr = startnode->next;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	fmt_memset(startnode, 0, sizeof(t_node));
}

t_node	*fmt_lstaddnew_back(t_node *lst)
{
	t_node	*new;

	if (!lst)
		return (NULL);
	new = malloc(sizeof(t_node));
	if (!fmt_memset(new, 0, sizeof(t_node)))
		return (NULL);
	fmt_lstlast(lst)->next = new;
	return (new);
}
