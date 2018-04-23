#include "ft_itoa.c"
#include <stdio.h>

int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			printf("%s\n", ft_itoa(atoi(av[i])));
			i++;
		}
	}
	return (0);
}