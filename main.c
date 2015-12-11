/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:15:27 by gahubaul          #+#    #+#             */
/*   Updated: 2015/12/10 16:15:30 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void  ft_error(char *str)
{
  int i;
  
  i = 0;
  while (str[i])
    write(1, str[i], 5);
  write(1, "\n", 1);
  exit;
}

void    ft_error(char *argv)
{
  char	buff[BUFF_SIZE + 1];
  char	**tab_tetri;
  int   file_descriptor;
  int		read_result;
  int		tetri_nomber;
  int		counter;
  int   x;
  int   y;
  int   k;
  
  if (file_descriptor = open(argv, O_RDONLY) == -1)
    ft_error("error");
  if ((read_result = read(file_descriptor, buff, BUFF_SIZE)) == -1)
    ft_error("error");
  buff[read_result] = '\0';
  if (close(file_descriptor) == -1)
		ft_error("error");
	if (((read_result + 1) % 21) != 0)
		ft_error("error");
	if ((tab_tetri = ft_strsplit(buff, '\n')) == NULL)
		ft_error("error");
	y = -1;
  while (tab_tetri[++y])
	{
		x = -1;
		while (tab_tetri[y][++x])
		{
			if (tab_tetri[y][x] != '#' && tab_tetri[y][x] != '.')
				ft_error("error");
		}
		if (x != 4)
			ft_error("error");
	}
	if ((y % 4) != 0)
		ft_error("error");
	if ((tetri_nb = (y / 4)) > 26)
		ft_error("error");
  x = -1;
  y = 0;
	counter = 0;
	while (tab_tetri[y])
	{
		k = -1;
		while (++k < 16)
		{
			if (tab_tetri[y][++x] == '#')
				counter++;
			if (((k + 1) % 4) == 0)
			{
				y++;
				x = -1;
			}
		}
		if ((counter % 4) != 0)
			ft_error("error");
	}
	return (0);

}

int     main(int argc, char **argv)
{ 
  if (argc != 2)
    ft_error("erreur"));
  else if (argc == 2)
    ft_error(argv[1]);
    return (0);
}
