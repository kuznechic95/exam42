/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:44:35 by exam              #+#    #+#             */
/*   Updated: 2018/05/22 12:28:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

int		sb(char *a, int *j)
{
	(*j)++;
	while (a[*j])
	{
		if (a[*j] == ']')
			return (1);
		if (a[*j] == ')' || a[*j] == '}')
			return (0);
		if (a[*j] == '(' && !rb(a, j))
			return (0);
		if (a[*j] == '[' && !sb(a, j))
			return (0);
		if (a[*j] == '{' && !bb(a, j))
			return (0);
		(*j)++;
	}
	return (0);
}