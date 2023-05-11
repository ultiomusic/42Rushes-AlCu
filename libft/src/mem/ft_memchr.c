/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:32:03 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 22:06:03 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
