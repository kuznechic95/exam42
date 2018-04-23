/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:13:44 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/08 20:02:54 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int		sign;
	int		res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{	
		ft_putchar(nbr + '0');
	}
}

int		ft_is_prime(int i)
{
	int m;

	m = 2;
	while (m < i)
	{
		if (i % m == 0)
			return (0);
		m++;
	}
	return (1);
}

void	ft_add_prime_sum(int n)
{
	int		i;
	int		sum;

	i = 2;
	sum = 0;
	if (n > 0)
	{
		while (i <= n)
		{
			if (ft_is_prime(i))
				sum += i;
			i++;
		}
	}
	ft_putnbr(sum);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_add_prime_sum(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
