/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 12:56:00 by gahubaul          #+#    #+#             */
/*   Updated: 2016/01/03 12:56:02 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (tab[y][x] == '#')
			return (1);
		y++;
	}
	return (0);
}