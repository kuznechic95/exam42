/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:39:09 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/03 20:03:25 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "ft_strcmp.c"

int		main(int ac, char	**av)
{
	if (ac == 3)
	{
		printf("%d\n", strcmp(av[1], av[2]));
		printf("%d\n", ft_strcmp(av[1], av[2]));
	}
	
	printf("%d\n", ft_strcmp("\200", "\0"));
	printf("%d\n", ft_strcmp("\200", "\0"));
}
