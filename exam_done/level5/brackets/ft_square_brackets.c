/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_brackets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:19:13 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/04 15:19:14 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int ft_square_brackets(char *str, int *i)
{
	printf("S\n");
	*i = *i + 1;
	while (str[*i])
	{
		if (str[*i] == '[')
		{
			if (ft_square_brackets(str, i) == 0)
				return (0);
		}
		else if (str[*i] == '{')
		{
			if (ft_figure_brackets(str, i) == 0)
				return (0);
		}
		else if (str[*i] == '(')
		{
			if (ft_round_brackets(str, i) == 0)
				return (0);
		}
		else if (str[*i] == ']')
		{
			printf("S - OK\n");
			return (1);
		}
		else if (str[*i] == ')' || str[*i] == '}')
			return (0);
		*i = *i + 1;
	}
	return (0);
}
