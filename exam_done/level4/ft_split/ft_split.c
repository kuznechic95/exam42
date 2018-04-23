/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:51:37 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 15:51:38 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_blank(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' || c == '\n' || \
	c == '\t' || c  == '\v');
}

int		ft_word_count(char *str)
{
	int	i;
	int	has_word;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		has_word = 0;
		while (ft_blank(str[i]) && str[i])
			i++;
		while (!(ft_blank(str[i])) && str[i])
		{
			has_word = 1;
			i++;
		}
		if (has_word == 1)
			word_count++;
	}
	return (word_count);
}

int		ft_word_size(char *str)
{
	int	i;

	i = 0;
	while (ft_blank(*str) && *str)
		str++;
	while (!(ft_blank(str[i])) && str[i])
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	int		word_count;
	int		word_entered;
	int		i;
	char	*word;
	char	**words;

	word_entered = 0;
	word_count = ft_word_count(str);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	while (word_entered < word_count)
	{
		i = 0;
		word = (char *)malloc(sizeof(char) * (ft_word_size(str)) + 1);
		while (ft_blank(*str) && *str)
			str++;
		while (!(ft_blank(*str)) && *str)
			word[i++] = *str++;
		word[i] = '\0';
		words[word_entered++] =  word;
	}
	words[word_entered] = 0;
	return (words);
}

