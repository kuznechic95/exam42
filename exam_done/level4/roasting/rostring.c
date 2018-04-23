/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:04:49 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/24 21:04:50 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			issep(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' || c == '\n' \
		|| c == '\t' || c == '\v');
}

void		rostring(char *s)
{
	int		i;
	int		word;
	int		first;
	int		first_end;

	i = 0;
	word = -1;
	while (s[i])
	{
		if (!issep(s[i]))
		{
			first = i;
			while (s[i] && !issep(s[i]))
				i++;
			first_end = i;
			break ;
		}
		i++;
	}
	while (s[i])
	{
		if (!issep(s[i]))
		{
			if (word != -1)
				write(1, " ", 1);
			word = i;
			while (s[i] && !issep(s[i]))
				i++;
			write(1, &s[word], i - word);
			continue ;
		}
		i++;
	}
	if (word != -1)
		write(1, " ", 1);
	write(1, &s[first], first_end - first);
}

int			main(int ac, char **av)
{
	if (ac == 2)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
