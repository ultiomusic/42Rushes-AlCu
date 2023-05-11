/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:06:55 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 21:53:42 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gfd.h"

void	gfd_print(t_gfd gfd)
{
	ft_pnerc(gfd.n_part, "");
	write(STDERR, "\n", 1);
	while (gfd.data && gfd.data->part)
	{
		ft_ps(gfd.data->part);
		gfd.data = gfd.data->next;
	}
}
