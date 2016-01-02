/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:34:49 by gahubaul          #+#    #+#             */
/*   Updated: 2016/01/02 15:34:53 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../Libft/libft.h"

void	ft_print_map(char **map, int size)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x <= size + 8)
		{
			if (map[y][x])
				ft_putchar(map[y][x]);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

char	**ft_creat_map(int size_map)
{
	char	**map;
	int y;

	y = 0;
	map = (char **)malloc(size_map * sizeof(char *));
	while (y < size_map)
	{
		map[y] = (char *)malloc(size_map *sizeof(char));
		y++;
	}
	return (map);
}

int		ft_check_line(char *string)
{
	int x;

	x = 0;
	while (tab[x])
	{
		if (tab[x] == '#')
			return (1);
		x++;
	}
	return (0);
}

int		ft_check_coll(char **tab)
{
	int y;
	int x;

	i = 0;
	y = 0;
	x = 0;
	while (tab[y][x])
	{
		if (tab[y][x] == '#')
			return (1);
		y++;
	}
	return (0);
}

char	**ft_cpy_tab_map(char **map, char **tab, int size_map)
{
	int x;
	int y;
	
	y = 0;
	while ()
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			map[y][x] = tab[y][x];
			x++;		
		}
		y++;
	}
	return (map);
}

void	ft_resolve(char *** tab)
{
	int z;
	int y;
	int x;
	int size_map;
	char **map;

	size_map = 4;
	map = ft_creat_map(size_map);
	z = 0;
	y = 0;
	x = 0;
	
	map = ft_cpy_tab_map(map, tab[z], size_map);
	ft_print_map(map, size_map);
}