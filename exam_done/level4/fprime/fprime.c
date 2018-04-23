/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:54:35 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 13:54:36 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int	i;
	int	nb;

	if (argc == 2)
	{
		nb = atoi(argv[1]);
		if (nb == 1)
		{
			printf("1\n");
			return (0);
		}
		while (1)
		{
			i = 2;
			while (i <= nb)
			{
				if (nb % i == 0)
				{
					printf("%d", i);
					nb /= i;
					break ;
				}
				i++;
			}
			if (nb == 1)
				break ;
			else
				printf("*");
		}
	}
	printf("\n");
	return (0);
}
