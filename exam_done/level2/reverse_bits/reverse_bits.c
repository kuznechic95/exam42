/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 22:09:48 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/28 19:05:53 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	res;
	int				count;

	res = 0;
	count = 8;
	while (count)
	{
		res = res * 2 + (unsigned char)(octet % 2);
		octet = octet / 2;
		count--;
	}
	return (res);
}

unsigned char	reverse_bits2(unsigned char octet)
{
	unsigned int	res;
	int				i;
	int				n;

	res = 0;
	i = 1;
	n = 128;
	while (n >= 1)
	{
		if (octet & i)
			res += n;
		i <<= 1;
		n >>= 1;
	}
	return (res);
}

void			print_bits(unsigned char octet)
{
	unsigned char x;

	write(1, "\t", 1);
	x = 128;
	while (x > 0)
	{
		if (x & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		x >>= 1;
	}
}

unsigned char	uchar_to_bin(unsigned char k)
{
	return (k == 0 || k == 1 ? k : ((k % 2) + 10 * uchar_to_bin(k / 2)));
}

unsigned char	ft_pow(unsigned char n, unsigned char i)
{
	unsigned char	j;
	unsigned char	res;

	j = 0;
	res = 1;
	while (j < i)
	{
		res *= n;
		j++;
	}
	return (res);
}

unsigned char	bin_to_uchar(unsigned char nbin)
{
	unsigned char	remainder;
	unsigned char	decimal;
	unsigned char	i;

	remainder = 0;
	decimal = 0;
	i = 0;
	while (nbin != 0)
	{
		remainder = nbin % 10;
		nbin = nbin / 10;
		decimal = decimal + (remainder * ft_pow(2, i));
		++i;
	}
	return (decimal);
}
