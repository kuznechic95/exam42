/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 19:23:31 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/25 19:34:46 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = av[1];
	if (ac == 2)
	{
		while (str[i] != '\0')
		{
			if (str[i] != 'z')
				i++;
			else
			{
				write(1, "z\n", 2);
				return (0);
			}
		}
		write(1, "z\n", 2);
	}
	else
		write(1, "z\n", 2);
	return (0);
}