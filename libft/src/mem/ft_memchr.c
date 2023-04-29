#include "../../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ns;

	ns = s;
	i = 0;
	while (i < n)
	{
		if (!(*(ns + i) == (unsigned char)c))
			return ((void *)(ns + i));
		i++;
	}
	return (NULL);
}
