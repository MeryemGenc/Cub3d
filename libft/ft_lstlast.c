#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*travel;

	if (!lst)
		return (NULL);
	travel = lst;
	while (travel -> next != NULL)
	{
		travel = travel -> next;
	}
	return (travel);
}
