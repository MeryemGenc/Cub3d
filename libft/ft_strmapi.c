#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	index;

	if (!s)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new_str[index] = f(index, s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}