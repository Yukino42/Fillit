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

int		ft_check_block(char *buff);
int		ft_count_back(char *buff);
int		ft_count_char_sharp_line(char *buff);
int		ft_count_sharp(char *buff);

void	ft_error_exit(char *str)
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

int		ft_count_char(char *buff)
{
	int i;
	
	i = 0;
	while(buff[i])
		i++;
	return (i);
}

void	ft_print_tab(char **tab)
{
	int i;
	int y;
	int x;
	
	i = 0;
	while(tab[y])
	{
		
	}
}

int		ft_count_line(char *buff)
{
	int i;
	int j;
	
	i = 0;
	j = -1;
	while(buff[i])
	{
		if (buff[i] == '\n')
			j++;
		i++;
	}
	return (j);
}
int		ft_seperator_tetri(int y)
{
	int i;
	
	i = 0;
	while(i < 140)
	{
		if (y == i)
			return (1);
		if (i == 0)
			i = i + 4;
		else
			i = i + 5;
	}
	return (0);
}

char	**ft_tab_buff(char *buff)
{
	char **tab;
	int i;
	int x;
	int y;
	
	tab[y] = (char **)malloc(sizeof(*tab[y]) * (ft_count_line(buff)));
	if (!tab)
		return (NULL);
	i = 0;
	y = 0;
	while(tab[y])
	{
		if (ft_seperator_tetri(y) != 1)
		{
			if((tab[y] = (char*)malloc(sizeof(tab[y]) * 4)))
				return (NULL);
		}
		else
			tab[y] = (char*)malloc(sizeof(tab[y]) * 1);
		y++;
	}
	while(buff[i])
	{
		x = 0;
		while(buff[i] != '\n')
		{
			write(1, "salut\n", 7);
			tab[y][x] = buff[i];
			write(1, "salput\n", 8);
			x++;
			i++;
		}
		tab[y][x] = buff[i];
		y++;
	}
	return (tab);
}

void    ft_error(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	int   	file_descriptor;
	int		read_result;
	int		tetri_nomber;

	if ((file_descriptor = open(argv, O_RDONLY)) == -1)
		ft_error_exit("error");
	if ((read_result = read(file_descriptor, buff, BUFF_SIZE)) == -1)
  		ft_error_exit("error");
	buff[read_result] = '\0';
	if (close(file_descriptor) == -1)
		ft_error_exit("error");
	if (((read_result + 1) % 21) != 0)
		ft_error_exit("error");
	if (ft_count_sharp(buff) == 0)
		ft_error_exit("error");
	if (ft_count_char_sharp_line(buff) == 0)
		ft_error_exit("error");
	if (ft_check_block(buff) == 0)
		ft_error_exit("error");
	if (ft_tab_buff(buff) == NULL)
		ft_error_exit("error1");
	ft_print_tab(ft_tab_buff(buff));
}

int     main(int argc, char **argv)
{ 
  if (argc == 2)
	ft_error(argv[1]);
  else if (argc != 2)
    ft_error_exit("erreur");
  return (0);
}
