#include "../../inc/libft.h"

int	ft_strcpy(char *dst, const char *src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(src);
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
