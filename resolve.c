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

void	ft_print_map(char **map);


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

int		ft_check_line(char *tab)
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

int		ft_check_coll(char **tab, int x, int y, int size_map)
{
	while (y < size_map)
	{
		write(1, "a ", 3);
		if (tab[y][x] == '#')
			return (1);
		y++;
	}
	return (0);
}

char	**ft_cpy_tetri(char **map, char **tab, int y, int x)
{
	int Y;
	int X;
	int j;
	int consty;
	int constx;
	
	j = 0;
	consty = y;
	constx = x;
	Y = 0;
	while(tab[y] && map[Y])
	{
		X = 0;
		constx = x;
		while (tab[constx] && map[X])
		{
			map[Y][X] = tab[y][constx];
			X++;
			constx++;
		}
		Y++;
		consty++;
	}
	return (map);
}

char 	**ft_print_tetri_map(char **map, char **tab, int size_map)
{
	int y;
	int x;
	
	y = 0;
	while (ft_check_line(tab[y]) != 1)
		y++;
	x = 0;
	while (ft_check_coll(tab, x, y, size_map) != 1)
		x++;
	write(1, "salut", 6);
	return (ft_cpy_tetri(map, tab, y, x));
}

void	ft_resolve(char *** tab, int size_map)
{
	int z;
	char **map;
	
	z = 0;
	map = ft_creat_map(size_map);
	// while (tab[z])
	// {
	// 	if ((ft_print_tetri_map(map, tab[z]) == NULL)
	// 		ft_resolve(tab, (size_map + 1));
	// 	map = (ft_print_tetri_map(map, tab[z])
	// 	z++;
	// }
	ft_print_map(ft_print_tetri_map(map, tab[z], size_map));
}