#include "../../inc/libft.h"

double	ft_atof(const char *str)
{
	double	res;
	double	neg;
	double	divider;
	size_t	i;

	divider = 0.1;
	res = 0;
	neg = 1;
	i = -1;
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + (str[i] - 48) * divider;
		divider /= 10;
		i++;
	}
	return (res * neg);
}
