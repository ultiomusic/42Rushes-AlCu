/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:09:31 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 21:53:25 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

ssize_t	ft_ps(const char *str)
{
	return (write(STDOUT, str, ft_strlen(str)));
}

ssize_t	ft_psc(const char *str, const char *color)
{
	return (write(STDOUT, color, ft_strlen(color))
		+ write(STDOUT, str, ft_strlen(str))
		+ write(STDOUT, DEF, ft_strlen(DEF)));
}

ssize_t	ft_pser(const char *str)
{
	return (write(STDERR, str, ft_strlen(str)));
}

ssize_t	ft_pserc(const char *str, const char *color)
{
	return (write(STDERR, color, ft_strlen(color))
		+ write(STDERR, str, ft_strlen(str))
		+ write(STDERR, DEF, ft_strlen(DEF)));
}
