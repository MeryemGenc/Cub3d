#include "libft.h"
#include "stdio.h"

int	ft_strrcmp(char *src, char *dest)
{
	int	srci;
	int	desti;

	srci = ft_strlen(src) - ft_strlen(dest);
	desti = 0;
	if (srci <= 0)
		return (0);
	while (src[srci] && dest[desti])
	{
		if (src[srci] != dest[desti])
			break ;
		srci++;
		desti++;
	}
	return (((unsigned char *)src)[srci] - ((unsigned char *)dest)[desti]);
}
