/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:47:16 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/25 18:58:43 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int		i;
	char	a;
	char	b;

	i = 0;
	a = 'a';
	b = 'B';
	while (i < 13)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		a += 2;
		b += 2;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}