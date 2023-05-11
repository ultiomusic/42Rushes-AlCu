/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:02:43 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 22:06:09 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	*ft_memmove_end(char *dest, const char *src, size_t n)
{
	int	i;

	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(dest + i) = *(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(dest + i) = *(src + i);
			i++;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ndest;
	const char	*nsrc;

	if (!dest && !src)
		return (NULL);
	ndest = dest;
	nsrc = src;
	return (ft_memmove_end(ndest, nsrc, n));
}
