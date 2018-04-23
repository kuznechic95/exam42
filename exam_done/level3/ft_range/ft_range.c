/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:44:15 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 11:44:17 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					*ft_range_up(int start, int end) {
	int				*tab;
	long long		n;
	long long		i;

	n = (long long)end - (long long)start;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))
		return (NULL);
	i = 0;
	while ((long long)start + i <= (long long)end)
	{
		tab[i] = start + i;
		i++;
	}
	return (tab);
}

int					*ft_range_down(int start, int end)
{
	int				*tab;
	long long		n;
	long long		i;

	n = (long long)start - (long long)end;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))
		return (NULL);
	i = 0;
	while ((long long)start - i >= (long long)end)
	{
		tab[i] = start - i;
		i++;
	}
	return (tab);
}

int			*ft_range(int start, int end)
{
	if (start < end)
		return (ft_range_up(start, end));
	return (ft_range_down(start, end));
}