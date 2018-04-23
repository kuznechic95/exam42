/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:05:34 by ovirchen          #+#    #+#             */
/*   Updated: 2018/04/04 18:31:16 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int			ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int			main(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			j = -1;
			while (av[i][++j])
			{
				if (av[i][j] == '(')
				{
					if (ft_round_brackets(av[i], &j) == 0)
						{
							ft_error();
							return (0);
						}
				}
				else if (av[i][j] == '[')
				{
					if (ft_square_brackets(av[i], &j) == 0)
					{
						ft_error();
						return (0);
					}
				}
				else if (av[i][j] == '{')
				{
					if (ft_figure_brackets(av[i], &j) == 0)
					{
						ft_error();
						return (0);
					}
				}
				else if (av[i][j] == ')' || av[i][j] == ']' || av[i][j] == '}')
				{
					ft_error();
					return (0);
				}
			}
			write(1, "OK\n", 3);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

