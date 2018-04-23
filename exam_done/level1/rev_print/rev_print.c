/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:07:10 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/26 18:24:13 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putstrrev(char *str)
{
	if (*str)
	{
		ft_putstrrev(str + 1);
		write(1, &(*str), 1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_putstrrev(av[1]);
	}
	write(1, "\n", 1);
}
