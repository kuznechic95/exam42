
#include <stdio.h>
#include "ft_itoa_base.c"

int main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	}
	else printf("\n");
	return (0);
}
