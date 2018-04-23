#include "ft_atoi_base.c"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if(argc == 3)
	{
		printf("%d\n", ft_atoi_base(argv[1], atoi(argv[2])));
	}
	else
		printf("error\n");
	return (0);
}