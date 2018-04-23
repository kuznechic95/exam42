/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:33:07 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/08 20:47:40 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int				ft_list_size(t_list *list)
{
	int			i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void			ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*temp;

	if (!alst || !new)
		return ;
	temp = *alst;
	new->next = temp;
	*alst = new;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len)
	{
		*p = (unsigned char)c;
		len--;
		p++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (!size)
		return (NULL);
	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	if (dst == src)
		return (dst);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return (dst);
}

t_list	*ft_lstnew(void const *data, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	if (!data)
	{
		node->data = NULL;
		return (node);
	}
	node->data = ft_memalloc(content_size);
	if (!(node->data))
	{
		free(node);
		return (NULL);
	}
	ft_memcpy(node->data, data, content_size);
	return (node);
}

int				main(void)
{
	t_list		*list;

	list = NULL;
	ft_lstadd(&list, ft_lstnew((void*)"a", sizeof(char)));
	ft_lstadd(&list, ft_lstnew((void*)"b", sizeof(char)));
	ft_lstadd(&list, ft_lstnew((void*)"с", sizeof(char)));
	printf("%d\n", ft_list_size(list));
	return (0);
}