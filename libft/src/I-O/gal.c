/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:50:56 by adelille          #+#    #+#             */
/*   Updated: 2023/04/29 21:53:37 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*gal_error(const int fd, char *output)
{
	if (fd != 0)
		close(fd);
	if (output)
		free(output);
	return (NULL);
}

static char	*gal_big(const int fd, char *output, size_t *size)
{
	ssize_t	res;
	size_t	capacity;

	capacity = GAL_BUFFER;
	res = 1;
	while (res > 0)
	{
		output = ft_str_extend(output, *size, *size + capacity + 1);
		res = read(fd, &output[*size], capacity);
		if (res < 0)
			return (gal_error(fd, output));
		if (res == 0)
			break ;
		*size += res;
		output[*size] = '\0';
		capacity *= 2;
	}
	if (fd != 0)
		close(fd);
	return (output);
}

char	*gal(const int fd, size_t *size, const bool all)
{
	char	*output;
	ssize_t	res;

	*size = 0;
	output = (char *)malloc(sizeof(char) * (GAL_INIT_BUFFER + 1));
	if (!output)
		return (gal_error(fd, output));
	res = read(fd, output, GAL_INIT_BUFFER);
	if (res < 0)
		return (gal_error(fd, output));
	output[res] = '\0';
	*size += res;
	if (res == 0 || (all == false && res < GAL_INIT_BUFFER))
		return (output);
	return (gal_big(fd, output, size));
}
