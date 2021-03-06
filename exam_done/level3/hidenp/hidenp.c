/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:17:03 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/08 21:17:41 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hidenp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s2 == *s1)
			s1++;
		s2++;
	}
	if (*s1 == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_hidenp(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
