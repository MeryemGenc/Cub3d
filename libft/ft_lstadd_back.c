#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*travel;

	if (*lst == NULL)
		*lst = new;
	else
	{
		travel = ft_lstlast(*lst);
		travel -> next = new;
	}
}
