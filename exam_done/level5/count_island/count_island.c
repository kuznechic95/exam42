/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:08:21 by exam              #+#    #+#             */
/*   Updated: 2017/11/28 13:08:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_isl.h"

void		print_str(char **str)
{
	int i;
	int j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			write(1, &str[i][j], 1);
		write(1, "\n", 1);
	}
}

static char	**create_island(char **str, int i, int j, char count)
{
	int jl;
	int	jr;

	str[i][j] = count;
	jl = j;
	while (jl >= 0)
	{
		if (str[i][jl] == 'X')
			str[i][jl] = count;
		else if (str[i][jl] == '.')
			break ;
		jl--;
	}
	jr = j;
	while (str[i][jr])
	{
		if (str[i][jr] == 'X')
			str[i][jr] = count;
		else if (str[i][jr] == '.')
			break ;
		jr++;
	}
	while (++jl < jr && str[i + 1])
	{
		if (str[i + 1][jl] == 'X')
			str = create_island(str, i + 1, jl, count);
	}
	while (i - 1 >= 0 && str[i][--jr] != '.')
	{
		if (str[i - 1][jr] == 'X')
			str = create_island(str, i - 1, jr, count);
	}
	return (str);
}

void		count_island(char **str)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'X')
			{
				str = create_island(str, i, j, count + 48);
				if (count == 10)
					return ;
				count++;
			}
		}
	}
	print_str(str);
}
