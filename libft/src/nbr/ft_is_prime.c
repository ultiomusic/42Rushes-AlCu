#include "../../inc/libft.h"

bool	ft_is_prime(int n)
{
	int	div;

	if (n == 2 || n == 3 || n == INT_MAX)
		return (true);
	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return (false);
	div = 5;
	while (div * div <= n)
	{
		if (n % div == 0 || n % (div + 2) == 0)
			return (false);
		div += 6;
	}
	return (true);
}

bool	ft_is_prime_ul(unsigned long n)
{
	unsigned long	div;

	if (n == 2 || n == 3)
		return (true);
	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return (false);
	div = 5;
	while (div * div <= n)
	{
		if (n % div == 0 || n % (div + 2) == 0)
			return (false);
		div += 6;
	}
	return (true);
}
