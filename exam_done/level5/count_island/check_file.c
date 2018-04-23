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
	int row;
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '.' || str[i][j] == 'X')
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
