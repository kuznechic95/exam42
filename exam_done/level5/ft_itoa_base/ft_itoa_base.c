/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:24:12 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/16 16:24:13 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					ft_istrlen(int v, int b)
{
	int				i;

	i = 1;
	while (v /= b)
		i++;
	return (i);
}

char				*ft_itoa_base(int value, int base)
{
	int				sign;
	int				len;
	unsigned int	n;
	char			*s;

	if (base < 2 || base > 16)
		return (0);
	sign = 0;
	if (value < 0)
	{
		if (base == 10)
			sign = 1;
		n = -value;
	}
	else
		n = value;
	len = ft_istrlen(n, base) + sign + 1;
	if (!(s = (char *)malloc(sizeof(char) * (len))))
		return (0);
	s[--len] = '\0';
	while (len >= 0)
	{
		if (n % base < 10)
			s[--len] = n % base + '0';
		else
			s[--len] = n % base + 'A' - 10;
		n /= base;
	}
	if (value < 0 && base == 10)
	{
		s[0] = '-';
	}
	return (s);
}
