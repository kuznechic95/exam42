/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:19:01 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/30 17:19:03 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*wdmatch(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 == *s2)
			s1++;
		s2++;
	}
	if (*s1 == '\0')
		return (s1);
	return (NULL);
}

int		main(int ac, char **av)
{
	char	*tmp;

	tmp = NULL;
	if (ac == 3)
	{
		tmp = wdmatch(av[1], av[2]);
		if (tmp != NULL)
			write(1, av[1], tmp - av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
