/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:26:08 by exam              #+#    #+#             */
/*   Updated: 2017/11/28 13:07:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_isl.h"
int		check_file(char **str)
{
	int i;
	int j;
	int	row;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'X' || str[i][j] == '.')
				j++;
			else
				return (0);
		}
		if (count == 0)
		{
			row = j;
			count = 1;
		}
		else if (row != j && j != 0)
			return (0);
	}
	return (1);
}