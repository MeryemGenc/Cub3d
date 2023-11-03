#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dest && !src)
		return (0);
	if (dest == src)
		return (dest);
	tmp = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (tmp);
}
