/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:04:32 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 21:53:23 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

ssize_t	ft_pn(int nbr)
{
	ft_putnbr_fd(nbr, STDOUT);
	return (ft_nbrlen(nbr));
}

ssize_t	ft_pner(int nbr)
{
	ft_putnbr_fd(nbr, STDERR);
	return (ft_nbrlen(nbr));
}

ssize_t	ft_pnc(int nbr, const char *color)
{
	ssize_t	size;

	size = write(STDOUT, color, ft_strlen(color));
	ft_putnbr_fd(nbr, STDOUT);
	size += ft_nbrlen(nbr);
	size += write(STDOUT, DEF, ft_strlen(DEF));
	return (size);
}

ssize_t	ft_pnerc(int nbr, const char *color)
{
	ssize_t	size;

	size = write(STDERR, color, ft_strlen(color));
	ft_putnbr_fd(nbr, STDERR);
	size += ft_nbrlen(nbr);
	size += write(STDERR, DEF, ft_strlen(DEF));
	return (size);
}
