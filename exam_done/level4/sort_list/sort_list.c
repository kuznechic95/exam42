/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:14:18 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/23 15:14:21 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list		*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmplst;
	int		swap;

	tmplst = lst;
	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmplst;
		}
		else
			lst = lst->next;
	}
	lst = tmplst;
	return (lst);
}
