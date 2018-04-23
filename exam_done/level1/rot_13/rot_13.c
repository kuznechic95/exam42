/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:02:45 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/26 19:14:54 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rot13(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
			ft_putchar(*str + 13);
		else if ((*str >= 'n' && *str <= 'z') || (*str >= 'N' && *str <= 'M'))
			ft_putchar(*str - 13);
		else
			ft_putchar(*str);
		str++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_rot13(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
