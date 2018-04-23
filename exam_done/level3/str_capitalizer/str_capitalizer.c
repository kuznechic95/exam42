/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:56:26 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 12:56:27 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		is_sep(char c)
{
	return (c == '\0' || c == ' ' || c == '\f' || c == '\r' \
						|| c == '\n' || c == '\t' || c == '\v');
}

int		ft_str_capitalizer(char *s)
{
	int i;

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
	i = 1;
	while (s[i])
	{
		if (is_sep(s[i - 1]))
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		else
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
		}
		i++;
	}
	ft_putstr(s);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			ft_str_capitalizer(av[i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
