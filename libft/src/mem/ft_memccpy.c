#include "../../inc/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ndest;
	const unsigned char	*nsrc;

	i = 0;
	ndest = dest;
	nsrc = src;
	while (i < n)
	{
		*(ndest + i) = *(nsrc + i);
		if (*(nsrc + i) == (unsigned char)c)
			return (ndest + i + 1);
		i++;
	}
	return (NULL);
}
