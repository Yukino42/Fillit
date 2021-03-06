#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../Libft/libft.h"

void		ft_error_exit(char *str)
{
	int		i;
	char	c;

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

void	ft_print_map(char **map, int size_map)
{
	int y;
	int x;

	y = 0;
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			if (map[y][x])
				ft_putchar(map[y][x]);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void		print_tab_3d(char ***tab, int count)
{
	int		x;
	int		y;
	int		z;

	z = 0;
	while (z < count)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				write(1, &tab[z][y][x], 1);
				x++;
			}
			y++;
			write(1, "\n", 1);
		}
		z++;
		if (z != count)
			write(1, "\n", 1);
	}
}
