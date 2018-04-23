/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:08:42 by exam              #+#    #+#             */
/*   Updated: 2017/11/28 13:07:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_isl.h"

static int	error(void)
{
	write(1, "\n", 1);
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;
	int		i;
	int		j;
	int		ret;
	char	buf;
	char	*str[1024];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (error());
		i = 0;
		j = 0;
		str[i] = (char *)malloc(sizeof(char) * 1024);
		while ((ret = read(fd, &buf, 1)))
		{
			if (ret == -1)
				return (error());
			if (buf == '\n')
			{
				str[i][j] = '\0';
				str[++i] = (char *)malloc(sizeof(char) * 1024);
				j = -1;
			}
			else
				str[i][j] = buf;
			j++;
		}
		if (buf != '\n')
			return (error());
		str[i] = 0;
		if (check_file(str) == 0)
			return (error());
		count_island(str);
	}
	else
		write(1, "\n", 1);
	return (0);
}
