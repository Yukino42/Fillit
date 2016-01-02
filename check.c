/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 16:20:01 by gahubaul          #+#    #+#             */
/*   Updated: 2015/12/26 16:20:08 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_sharp(char *buff)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			counter++;
		i++;
	}
	if ((counter % 4) != 0)
		return (0);
	return (1);
}

int		ft_count_char_sharp_line(char *buff)
{
	int i;
	int j;
	int new;
	int sharp;

	i = 0;
	j = 0;
	new = 0;
	sharp = 0;
	while (buff[i] != '\0')
	{
		while (buff[i] != '\n' && buff[i])
		{
			if (buff[i] == '#')
				sharp++;
			i++;
			j++;
		}
		new++;
		if (j != 4 && (new % 4) != 0 && sharp % 4 != 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int		ft_count_back(char *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			j++;
		i++;
	}
	return (j);
}

int		ft_check_block(char *buff)
{
	int i;
	int j;
	int new;

	i = 0;
	while (buff[i])
	{
		j = 0;
		new = 0;
		while (new <= 4 && buff[i])
		{
			if (buff[i] == '\n')
				new++;
			if ((i > 5) && buff[i - 5] && buff[i - 5] == '#' && buff[i] == '#')
				j++;
			if (buff[i - 1] && buff[i - 1] == '#' && buff[i] == '#')
				j++;
			if (buff[i + 1] && buff[i + 1] == '#' && buff[i] == '#')
				j++;
			if (buff[i + 5] && buff[i + 5] == '#' && buff[i] == '#'
				&& (ft_count_back(buff) - 1) != new)
				j++;
			i++;
		}
		if (j < 6)
			return (0);
	}
	return (1);
}
