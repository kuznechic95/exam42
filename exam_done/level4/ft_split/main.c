/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:51:43 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 15:51:44 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_split.c"

int		main(void)
{
	char	**ar;
	char	*a = "\f  \n\r    \v                         \v \t      ";
	int		i;

	i = 0;
	ar = ft_split(a);
	while (ar[i])
	{
		printf("%s\n", ar[i]);
		i++;
	}
	return (0);
}
