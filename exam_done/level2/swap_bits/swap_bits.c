/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:57:16 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/28 19:57:23 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4 & 0x0F) | (octet << 4 & 0xF0));
}
