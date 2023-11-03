#include "libft.h"

int	ft_isspace(int c)
{
	if (c)
		if ((c >= 9 && c <= 13) || c == ' ')
			return (c);
	return (0);
}
