/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:54:03 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 16:54:08 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		put_char(char c)
{
	write(1, &c, 1);
}

int			is_blank(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' \
			|| c == '\n' || c == '\t' || c == '\v');
}

void		put_word(char *str)
{
	while (*str && !is_blank(*str))
		write(1, str++, 1);
}

int			main(int ac, char **av)
{
	int		i;
	char	*a;

	if (ac == 2)
	{
		a = av[1];
		i = 0;
		while (a[i])
			i++;
		i--;
		while (a[i] && i > 0)
		{
			while (a[i] && !is_blank(a[i]))
				i--;
			put_word(a + i + (i == 0 ? 0 : 1));
			while (is_blank(a[i]) && i > 0)
				i--;
			if (i > 0)
				put_char (' ');
		}
	}
	put_char('\n');
}
