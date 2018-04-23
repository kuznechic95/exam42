/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:27:05 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/26 18:44:10 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_srep(char *str, char old, char new)
{
	while (*str)
	{
		if (*str == old)
			write(1, &new, 1);
		else
			write(1, &(*str), 1);
		str++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 4 && av[2][1] == '\0' && av[3][1] == '\0')
	{
		ft_srep(av[1], *(av[2]), *(av[3]));
	}
	write(1, "\n", 1);
	return (1);
}
