/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:40:46 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/28 20:40:47 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	alpha_mirror(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			ft_putchar('m' - (s[i] - 'n'));
		else if (s[i] >= 'A' && s[i] <= 'Z')
			ft_putchar('M' - (s[i] - 'N'));
		else
			ft_putchar(s[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		alpha_mirror(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
