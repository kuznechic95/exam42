/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:18:16 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/16 16:18:18 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void		ft_brainfuck(char *str)
{
	size_t	i;
	ssize_t	count;
	char	*p;

	p = (char *)malloc(sizeof(char) * (2049));
	i = 0;
	while (i < 2048)
		p[i++] = 0;
	i = 0;
	while (str[i])
	{
		count = 1;
		if (str[i] == '>')
			p++;
		else if (str[i] == '<')
			p--;
		else if (str[i] == '+')
			(*p)++;
		else if (str[i] == '-')
			(*p)--;
		else if (str[i] == '[' && *p == 0)         
		{
			while (count > 0)
			{
				i++;
				if (str[i] == '[')
					count++;
				else if (str[i] == ']')
					count--;
			}
		}
		else if (str[i] == ']' && *p != 0)
		{
			while (count > 0)
			{
				i--;
				if (str[i] == ']')
					count++;
				else if (str[i] == '[')
					count--;
			}
		}
		else if (str[i] == '.')
			write(1, p, 1);
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		ft_brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
