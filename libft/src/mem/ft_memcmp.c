/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:43:11 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 22:06:05 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ns1;
	const unsigned char	*ns2;

	ns1 = s1;
	ns2 = s2;
	i = 0;
	while (i < n)
	{
		if (*(ns1 + i) != *(ns2 + i))
			return (*(ns1 + i) - *(ns2 + i));
		i++;
	}
	return (0);
}
