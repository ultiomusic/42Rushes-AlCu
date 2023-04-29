#include "../../inc/libft.h"

char
	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)s);
	i = 0;
	while (i < len && s[i])
	{
		j = 0;
		while (s[i + j] && to_find[j]
			&& i + j < len && s[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
