/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:05:30 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/30 18:05:32 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_do_op(int n1, char *sign, int n2)
{
	char s;

	s = sign[0];
	if (s == '+')
		printf("%d", n1 + n2);
	else if (s == '-')
		printf("%d", n1 - n2);
	else if (s == '*')
		printf("%d", n1 * n2);
	else if (s == '/')
		printf("%d", n1 / n2);
	else if (s == '%')
		printf("%d", n1 % n2);
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		ft_do_op(atoi(argv[1]), argv[2], atoi(argv[3]));
	}
	printf("\n");
	return (0);
}
