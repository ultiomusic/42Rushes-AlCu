/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:38:51 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 22:05:59 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	dst = malloc(nmemb * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, nmemb * size);
	return (dst);
}
