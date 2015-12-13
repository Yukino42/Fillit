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
#include "../Libft/libft.h"
#define BUFF_SIZE 545
#include <stdio.h>

void  ft_error_exit(char *str)
{
  int i;
  char c;
  
  i = 0;
  while (str[i])
  {
	  c = str[i];
	  write(1, &c, 5);
	  i++;
  }
  write(1, "\n", 1);
  exit(0);
}

int		ft_check_diez_block(char **tab, int Y, int X)
{
	int i;
	int y;
	int x;
	int line;

	x = X;
	y = Y;
	i = 0;
	line = 0;
	if (((y-1) %4) == 0)
		line++;
	else if ((tab[y][X]) == '#')
		i++;
	if((tab[Y][x-1]) == '#')
		i++;
	if((tab[Y][x+2]) == '#')
		i++;
	if((tab[y+2][X]) == '#')
		i++;
	if (i == 0)
		return (0);
	return (1);
}

void	ft_print_tetri(char **tab)
{
	int x;
	int y;
	char c;

	x = 0;
	y = 0;	
	while(tab[y])
	{
		while(tab[y][x])
			{
				c = tab[y][x];
				write(1, &c, 1);
				x++;
			}
			write(1, "\n", 1);
			y++;
			x = 0;			
	}
	exit(0);
}



void    ft_error(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	char	**tab;
	int   	file_descriptor;
	int		read_result;
	int		tetri_nomber;
	int		counter;
	int   	x;
	int   	y;
	int   	k;
	int 	fake;

	if ((file_descriptor = open(argv, O_RDONLY)) == -1)
		ft_error_exit("error1");
	if ((read_result = read(file_descriptor, buff, BUFF_SIZE)) == -1)
  		ft_error_exit("error2");
	buff[read_result] = '\0';
	if (close(file_descriptor) == -1)
		ft_error_exit("error3");
	if (((read_result + 1) % 21) != 0)
		ft_error_exit("error4");
	if ((tab = ft_strsplit(buff, '\n')) == NULL)
		ft_error_exit("error5");
	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (tab[y][x] != '#' && tab[y][x] != '.')\
				ft_error_exit("error6");
		}
		if (x != 4)
			ft_error_exit("error7");
	}
	if ((y % 4) != 0)
		ft_error_exit("error8");
	if ((tetri_nomber = (y / 4)) > 26)
		ft_error_exit("error9");
	x = -1;
	y = 0;
	counter = 0;
	fake = 0;
	while (tab[y])
	{
		k = -1;
		while (++k < 16)
		{
			if (tab[y][++x] == '#')
			{
				fake++;
				if ((ft_check_diez_block(tab, y, x)) == 0)
				{
					ft_putnbr(fake);
					write(1, " ", 1);
					ft_error_exit("error10");
				}	
				counter++;
			}
				counter++;
			if (((k + 1) % 4) == 0)
			{
				y++;
				x = -1;
			}
		}
		if ((counter % 4) != 0)
			ft_error_exit("error11");
	}
	ft_print_tetri(tab);
}

int     main(int argc, char **argv)
{ 
  if (argc != 2)
    ft_error("erreur");
  else if (argc == 2)
    ft_error(argv[1]);
  return (0);
}
