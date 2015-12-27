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

void	ft_print_tab(char ***tab)
{
	int i;
	
	i = 0;
	while(tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int		ft_count_char(char *buff)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(buff[i])
	{
		if(buff[i] != '\n')
			j++;
		i++;
	}
	return (j);
}
char ***ft_send_tab(char *buff)
{
	char ***tab;
	int i;
	int rev;
	int x;
	int y;
	int z;
	
	i = 0;
	z = 0;
	if ((tab = (char ***)malloc(sizeof(**tab) *(ft_count_char(buff) +1))))
		return (NULL);
	while(buff[i])
	{
		rev = 0;
		y = 0;
		x = 0;
		while(rev != 4 && buff[i])
		{
			if (buff[i] != '\n')
				tab[y][x] = buff[i];
			if (buff[i] == '\n')
			{
				rev++;
				y++;
			}
			i++;
			x++;
		}
		z++;
		i++;
	}
	return (tab);
}

void    ft_error(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	char	***tab;
	int   	file_descriptor;
	int		read_result;
	int		tetri_nomber;

	if ((file_descriptor = open(argv, O_RDONLY)) == -1)
		ft_error_exit("error1");
	if ((read_result = read(file_descriptor, buff, BUFF_SIZE)) == -1)
  		ft_error_exit("error2");
	buff[read_result] = '\0';
	if (close(file_descriptor) == -1)
		ft_error_exit("error3");
	if (((read_result + 1) % 21) != 0)
		ft_error_exit("error4");
	if (ft_count_sharp(buff) == 0)
		ft_error_exit("error5");
	if (ft_count_char_sharp_line(buff) == 0)
		ft_error_exit("error5");
	if (ft_check_block(buff) == 0)
		ft_error_exit("error6");
	if ((tab = (ft_send_tab(buff))) == NULL)
		ft_error_exit("error7");
	ft_print_tab(tab);
}

int     main(int argc, char **argv)
{ 
  if (argc == 2)
	ft_error(argv[1]);
  else if (argc != 2)
    ft_error_exit("erreur");
  return (0);
}