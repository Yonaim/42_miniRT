
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*first;

	first = NULL;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, newnode);
		lst = lst->next;
	}
	return (first);
}
