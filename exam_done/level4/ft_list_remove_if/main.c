/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:15:34 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 18:15:37 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_remove_if.c"
#include <stdio.h>
#include <string.h>

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;
	return ((int)(*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i)));
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}


t_list		*ft_lstnew(void const *data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->data = malloc(sizeof(char) * (strlen(data) + 1));
	ft_memcpy(list->data, data, strlen(data) + 1);
	list->next = NULL;
	return (list);
}

int			main(void)
{
	t_list	*list;

	list = ft_lstnew("one");
	list->next = ft_lstnew("one");
	list->next->next = ft_lstnew("one");
	list->next->next->next = ft_lstnew("my");
	list->next->next->next->next = ft_lstnew("world");
	list->next->next->next->next->next = ft_lstnew("one");
	
	ft_list_remove_if(&list, "one", &ft_strcmp);
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
	return (0);
}
