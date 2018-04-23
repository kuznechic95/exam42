#include "ft_atoi.c"
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", ft_atoi(av[1]));
	}
	return (0);
}
