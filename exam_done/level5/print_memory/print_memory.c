/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:25:11 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/16 16:25:14 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		print_bit(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void		print_mem(char *ps, size_t t, size_t size)
{
	size_t	i;

	i = t;
	while (i < t + 16 && i < size)
	{
		print_bit(ps[i]);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < t + 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	i = t;
	while (i < t + 16 && i < size)
	{
		if (ps[i] > 31 && ps[i] < 127)
			write(1, &ps[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void		print_memory(const void *addr, size_t size)
{
	size_t	t;
	char	*ps;

	t = 0;
	ps = (char *)addr;
	while (t < size)
	{
		print_mem(ps, t, size);
		t += 16;
	}
}

int			main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16,  \
		21, 42, 2147483647, -2147483648};

	print_memory(tab, sizeof(tab));
	return (0);
}
