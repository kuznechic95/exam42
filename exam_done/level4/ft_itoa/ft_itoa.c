/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:49:33 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/23 15:49:36 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int 	ft_str_len(unsigned int n)
{
	int i;

	i = 1;
	while (n /= 10)
	{
		i++;
	}
	return (i);
}

char	*ft_str_new(int len)
{
	int				i;
	char			*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	unsigned int	n;
	int 			len;
	char 			*str;
	int 			sign;

	sign = 0;
	str = 0;
	if (nbr < 0)
	{
		n = -nbr;
		sign = 1;
	}
	else
		n = nbr;
	len = ft_str_len(n) + sign;
	if (!(str = ft_str_new(len)))
		return (NULL);
	while (len >= 0)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	if (nbr < 0)
		*str = '-';
	return (str);
}