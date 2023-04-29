#include "../../inc/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*ns;

	ns = s;
	i = 0;
	while (i < len)
	{
		*(ns + i) = (unsigned char)c;
		i++;
	}
	return (ns);
}
