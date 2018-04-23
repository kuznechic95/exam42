/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:30:30 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/09 20:30:31 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_abs(int val)
{
	return ((val < 0) ? -val : val);
}

int		ft_pgcd(int a, int b)
{
	int c;

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return (ft_abs(a));
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", ft_pgcd(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}
