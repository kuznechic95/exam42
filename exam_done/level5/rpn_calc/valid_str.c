/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:32:54 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 12:50:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int valid_str(char *str)
{
	int count_num;
	int count_oper;
	int i;

	i = 0;
	while (*str)
	{
		count_num = 0;
		count_oper = 0;
		if (i == 1)
			count_num = 1;
		if (atoi(str) == 0 && *str != '0')
				return (0);
		while ((*str && atoi(str) != 0) || *str == '0')
		{
			count_num++;
			str++;
			while (*str >= '0' && *str <= '9')
				str++;
			if (*str == ' ')
				str++;
			else
				return (0);
			i = 1;
		}
		while (*str && (*str == '+' || *str == '-' ||
				   	*str == '*' || *str == '/' || *str == '%'))
		{
			count_oper++;
			str++;
			if (*str == ' ')
			{
				str++;
				if (!(*str))
					return (0);
			}
			else if (*str)
				return (0);
		}
		if (count_num != count_oper + 1)
			return (0);
	}
	return (1);
}
