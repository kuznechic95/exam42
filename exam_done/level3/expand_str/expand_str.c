/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 20:53:14 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/10 20:53:15 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_sep(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' \
			|| c == '\n' || c == '\t' || c == '\v');
}

void	ft_expand_str(char *str)
{
	while (is_sep(*str))
		str++;
	while (*str)
	{
		if (is_sep(*str))
		{
			while (is_sep(*str))
				str++;
			if (*str)
			{
				ft_putchar(' ');
				ft_putchar(' ');
				ft_putchar(' ');
			}
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_expand_str(av[1]);
	}
	ft_putchar('\n');
	return (0);
}
