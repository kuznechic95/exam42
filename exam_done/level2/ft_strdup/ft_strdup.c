/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:45:54 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/27 20:44:44 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int size;

	size = 0;
	while (*str)
	{
		str++;
		size++;
	}
	return (size);
}

char			*ft_strdup(char *src)
{
	char			*des;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = ft_strlen(src);
	if (!(des = (char *)malloc(sizeof(char) * (size + 1))))
	{
		des = NULL;
	}
	else
		while (i < size)
		{
			*(des + i) = *(src + i);
			i++;
		}
	*(des + i) = '\0';
	return (des);
}
