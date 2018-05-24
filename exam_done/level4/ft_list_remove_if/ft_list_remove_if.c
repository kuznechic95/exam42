/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:34:31 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/12 18:34:33 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_lst_clean(t_list *node)
{
	if (!node)
		return ;
	free(node);
	node = NULL;
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*previous;
	t_list		*current;
	t_list		*following;

	current = *begin_list;
	following = current->next;
	while (cmp(list->data, data_ref) == 0)
	{
		ft_lst_clean(current);
		current = following;
		*begin_list = current;
		following = current->next;
	}
	while (current)
	{
		following = current->next;
		if ((*cmp)(current->data, data_ref) == 0)
		{
			previous->next = following;
			ft_lst_clean(current);
		}
		else
			previous = current;
		current = following;
	}
}
