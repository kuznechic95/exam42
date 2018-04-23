/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiven <tpiven@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:04:44 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 21:12:01 by tpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int 		ft_down(char c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

int 		ft_audit(char *s, char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (ft_down(s[i]) == c)
			return (0);
		i++;
	}
	return (1);
}

int 		ft_comma(char *s, int n)
{
	int		i;
	int		j;
	int 	k;
	int		res;

	i = n;
	k = 0;
	res = 0;
	while (s[i])
	{
		if (ft_down(s[i]) >= 97 && ft_down(s[i]) <= 122)
		{
			j = 0;
			while (j < n)
			{
				if (ft_down(s[i]) == ft_down(s[j]))
				{
					res++;
					break;
				}
				j++;
			}
		}
		else
			k++;
		i++;
	}
	if (res == i - n - k || k == i - n)
		return (0);
	return (1);
}

int 		main(int ac, char **ar)
{
	char	*s;
	int		i;
	int		j;
	int		res;
	char	c;

	i = 0;
	if (ac == 2)
	{
		s = ar[1];
		while (s[i])
		{
			res = 0;
			if ((ft_down(s[i]) >= 97 && ft_down(s[i]) <= 122) \
				&& ft_audit(s, ft_down(s[i]), i))
			{
				j = 0;
				c = ft_down(s[i]);
				while (s[j])
				{
					if (ft_down(s[j]) == c)
						res++;
					j++;
				}
				printf("%d%c", res, c);
				if (ft_comma(s, i + 1))
					printf(", ");
			}
			i++;
		}
	}
	printf("\n");
}