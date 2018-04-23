/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:53:37 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/09 20:53:39 by okuzniet         ###   ########.fr       */
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

int		ft_rstr_capitalizer(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (is_sep(s[i + 1]))
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
			ft_rstr_capitalizer(av[i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
