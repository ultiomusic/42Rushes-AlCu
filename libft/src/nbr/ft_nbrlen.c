/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:39:24 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 22:06:18 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_nbrlen(int nb)
{
	unsigned int	n;
	int				i;

	if (nb == 0)
		return (1);
	i = 0;
	if (nb < 0)
	{
		n = -nb;
		i++;
	}
	else
		n = nb;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
