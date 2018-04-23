/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:15:59 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/26 19:58:55 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SPACE(x) (x == ' ' || x == '\n' || x == '\t')

void	ft_fw(char *str)
{
	while (SPACE(*str))
		str++;
	while (*str && !SPACE(*str))
	{
		write(1, &(*str), 1);
		str++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_fw(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
