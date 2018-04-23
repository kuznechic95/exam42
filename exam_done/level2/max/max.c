/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 21:18:25 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/28 21:18:26 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 1;
	max = 0;
	if (len != 0)
	{
		max = tab[0];
		while (i < len)
		{
			if (max < tab[i])
				max = tab[i];
			i++;
		}
	}
	return (max);
}
