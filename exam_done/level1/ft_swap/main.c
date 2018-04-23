#include "ft_swap.c"
#include <stdio.h>

int	main(void)
{
	int a;
	int b;

	a = 45;
	b = 98;

	printf("a = %d\nb = %d\n", a, b);
	ft_swap(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
}
