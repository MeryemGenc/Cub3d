#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cup;

	tmp = *lst;
	while (tmp)
	{
		cup = tmp -> next;
		(*del)(tmp -> content);
		free(tmp);
		tmp = cup;
	}
	*lst = NULL;
}
