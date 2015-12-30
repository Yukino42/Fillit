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

int		count_tetri(char *buff)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(buff[i])
	{
		if(buff[i] != '\n')
			count++;
		i++;
	}
	count = count / 16;
	return (count);
}

char 	***add_tetri_to_table(char *buff, char ***table, int count)
{
	int i;
	int z;
	int y;
	int x;
	
	i = 0;
	z = 0;
	while(z < count)
	{
		y = 0;
		while(y < 4)
		{
			x = 0;
			while(x < 4)
			{
				if(buff[i] != '\n')
				{
					table[z][y][x] = buff[i];
					x++;
				}
				i++;
			}
			y++;
		}
		z++;
	}
	return(table);
}

char	***ft_tab_buff(char *buff)
{
	char ***table;
	int z;
	int y;
	
	table = (char ***)malloc( count_tetri(buff) * sizeof(char **));
	z = 0;
	while(z < count_tetri(buff))
	{
		table[z] = (char **)malloc(4 * sizeof(char*));
		y = 0;
		while(y < 4)
		{
			table[z][y] = (char *)malloc(4 * sizeof(char));
			y++;
		}
		z++;
	}
	if (!table)
		return (NULL);
	return (add_tetri_to_table(buff, table, count_tetri(buff)));
}

void	print_tab_3D(char ***tab, int count)
{
	int x;
	int y;
	int z;
	
	z = 0;
	while(z < count)
	{
		y = 0;
		while(y < 4)
		{
			x = 0;
			while(x < 4)
			{
				write(1, &tab[z][y][x],1);
				x++;
			}
			y++;
			write(1, "\n", 1);
		}
		write(1, "\n", 1);
		z++;
	}
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
	print_tab_3D(ft_tab_buff(buff), count_tetri(buff));	
}

int     main(int argc, char **argv)
{ 
  if (argc == 2)
	ft_error(argv[1]);
  else if (argc != 2)
    ft_error_exit("erreur");
  return (0);
}
