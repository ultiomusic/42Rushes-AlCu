#include "../../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ndest;
	const char	*nsrc;

	ndest = dest;
	nsrc = src;
	if (!ndest && !nsrc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(ndest + i) = *(nsrc + i);
		i++;
	}
	return (ndest);
}
