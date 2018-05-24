/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:44:26 by exam              #+#    #+#             */
/*   Updated: 2018/05/22 13:15:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int		brackets(char **av, int i, int *j)
{
	if (av[i][*j] == ')' || av[i][*j] == ']' || av[i][*j] == '}')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (av[i][*j] == '(' && !rb(av[i], j))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (av[i][*j] == '[' && !sb(av[i], j))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (av[i][*j] == '{' && !bb(av[i], j))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	ft_cycle(char **av)
{
	int		i;
	int		*j;
	int		j_;
	int		er;

	j = &j_;
	i = 0;
	while (av[++i])
	{
		er = 0;
		j_ = -1;
		while (av[i][++(*j)])
		{
			if (!brackets(av, i, j))
			{
				er = 1;
				break ;
			}
		}
		if (!er)
			write(1, "OK\n", 3);
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_cycle(av);
	}
	else
		write(1, "\n", 1);
	return (0);
}
