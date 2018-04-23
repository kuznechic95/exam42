/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:24:05 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 12:55:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_istrlen(int v, int b)
{
	int	i;

	i = 0;
	while (v /= b)
		i++;
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	unsigned int	n;
	int				len;
	char			*str;
	int				sign;

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
	if (!(str = (char *)malloc(sizeof(char) * (len))))
		return (0);
	str[--len] = '\0';
	while (len >= 0)
	{
		if (n % base < 10)
			str[len] = n % base + '0';
		else
			str[len] = n % base + 'A' - 10;
		n = n / base;
		len--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}


#define ABS(x) (x < 0 ? -x : x)

#include <stdlib.h>

#include <stdio.h>

int		size_nb(int v, int b)
{
	int i;

	i = 1;
	if ((v < 0 && b == 10))
		i++;
	v = v / b;
	while (v)
	{
		v = v / b;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	char *res;
	int i;
	int j;
	char *tab;
	int sign = 1;

	tab = "0123456789ABCDEF";
	i = size_nb(value, base);
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	j = 0;
	if (value < 0 && base == 10)
	{
		res[0] = '-';
		sign = -1;
		j++;
	}
	while (j <= --i)
	{
		res[i] = tab[(value % base) * sign];
		value = value / base;
	}
	return (res);
}

int main(void)
{
	printf("%s\n", ft_itoa_base(-2147483648, 10));
	return (0);
}







#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int	n;
	int				i;
	unsigned int	j;
	char			*str;
	int				sign;

	if (base < 2 || base > 16)
		return (0);
	i = 0;
	sign = 0;
	j = base - 1;
	if (value < 0)
	{
		if (base == 10)
			sign = 1;
		n = -value;
	}
	else
		n = value;
	while (n > j)
	{
		n = n / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 2 + sign));
	if (value < 0)
		n = -value;
	else
		n = value;
	i = i + sign;
	str[i + 1] = '\0';
	while (i >= 0)
	{
		if (n % base < 10)
			str[i] = n % base + '0';
		else
			str[i] = n % base + 55;
		n = n / base;
		i--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
