#include <stdio.h>
#include <stdlib.h>
#include "sort_list.c"

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*ft_lstnew(int a)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->data = a;
	list->next = NULL;
	return (list);
}

int main(void)
{
	t_list *list;

	int a = -114, b = -98, c = -7, d = 0, e = 34, f = 78;
	list = ft_lstnew(f);
	list->next = ft_lstnew(e);
	list->next->next = ft_lstnew(d);
	list->next->next->next = ft_lstnew(c);
	list->next->next->next->next = ft_lstnew(b);
	list->next->next->next->next->next = ft_lstnew(a);

	list = sort_list(list, &ascending);
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	return (0);

}