/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:16:09 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 14:43:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

int	main(int ac, char **av)
{
	if (ac != 3)
		write(1, "Error\n", 6);
	else
		add_two(av[1], av[2]);
	return (0);
}
