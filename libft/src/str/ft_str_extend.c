#include "../../inc/libft.h"

char	*ft_str_extend(char *str, const size_t size, const size_t capacity)
{
	char	*output;

	if (size >= capacity)
		return (str);
	output = (char *)malloc(sizeof(char) * capacity);
	if (!output)
		return (NULL);
	ft_strocpy(output, str, size);
	free(str);
	return (output);
}
