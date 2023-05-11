/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:23:18 by beeligul          #+#    #+#             */
/*   Updated: 2023/04/29 21:23:19 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/alcu.h"

bool	clear_map(t_map *map)
{
	if (map->map)
		free(map->map);
	return (false);
}

static bool	check_extension(const char *file_name)
{
	size_t	i;
	size_t	j;
	char	*ext;

	ext = ".map\0";
	i = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	j = 0;
	while (file_name[i + j] && ext[j] && file_name[i + j] == ext[j])
		j++;
	if (j == 4 && file_name[i + j] == '\0' && ext[j] == '\0')
		return (true);
	return (error("wrong map extension", 0));
}

static bool	init_map(const int ac, char **av, t_map *map, int *fd)
{
	if (ac == 1)
		*fd = STDIN;
	else if (ac == 2)
	{
		if (!check_extension(av[1]))
			return (false);
		*fd = open(av[1], O_RDONLY);
		if (*fd == -1)
			return (error("can't open file", 0));
	}
	else
	{
		error(NULL, 0);
		return (!ft_pserc("Please enter a board in parameter or in stdin\n",
				C_BOLD));
	}
	map->map = NULL;
	map->n_item = 0;
	map->n_heap = 0;
	map->winner = NO_WIN;
	return (true);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	if (!init_map(ac, av, &map, &fd))
		return (1);
	if (!parse(&map, fd))
		return (2);
	ft_ps("\033[1;1H\033[2J\v\v");
	print_map(map);
	ia(&map);
	while (map.n_item > 0)
	{
		print_map(map);
		if (prompt(&map))
			break ;
		ft_ps("\033[1;1H\033[2J\v\v");
		print_map(map);
		ia(&map);
	}
	print_winner(map.winner);
	clear_map(&map);
	return (0);
}
