/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:34:22 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/09 20:34:23 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_atoi_for_printhex(char *str)
{
	int		i;
	int		result;

	i = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
		str++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void		ft_print_hex(int n)
{
	int		c;

	if (n >= 16)
		ft_print_hex(n / 16);
	if (n % 16 < 10)
	{
		c = n % 16 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n % 16 - 10 + 'a';
		write(1, &c, 1);
	}
}

int			main(int ac, char **av)
{
	int		nb;

	if (ac == 2)
	{
		if ((nb = ft_atoi_for_printhex(av[1])) != -1)
			ft_print_hex(nb);
	}
	write(1, "\n", 1);
	return (0);
}
