/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:04:05 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/08 20:31:59 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;
	char	*str;

	if (ac == 2)
	{
		i = -1;
		str = av[1];
		while (*str != '\0')
		{
			while (*str == ' ' || *str == '\t' || *str == '\n')
				str++;
			if (i != -1 && *str != '\0')
				write(1, " ", 1);
			i = 0;
			while (str[i] != '\0' && str[i] != ' ' && \
					str[i] != '\t' && str[i] != '\n')
				i++;
			write(1, str, i);
			str = str + i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
