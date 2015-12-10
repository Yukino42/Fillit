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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void   ft_error(int i)
{
  (void)i;
  write(1, "erreur", 6);
  write(1, "\n", 1);
}

void   ft_read_argv(char *argv)
{
  char *str;
  int i;

  i = 0;

  str = open(argv);
  printf("%s", str);
}


int     main(int argc, char **argv)
{ 
  if (argc != 2)
    return (ft_error(0));
  else if (argc == 2)
    ft_read_argv(*argv);
}
