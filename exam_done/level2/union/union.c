/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:12:21 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/28 20:12:23 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int			used[128];
	int			i;

	i = -1;
	while (i < 128)
		used[++i] = 0;
	i = -1;
	while (s1[++i])
	{
		if (!used[(int)s1[i]])
		{
			write(1, &s1[i], 1);
			used[(int)s1[i]] = 1;
		}
	}
	i = -1;
	while (s2[++i])
	{
		if (!used[(int)s2[i]])
		{
			write(1, &s2[i], 1);
			used[(int)s2[i]] = 1;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
