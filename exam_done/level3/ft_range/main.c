#include "ft_range.c"
#include <stdio.h>

int				main(int argc, char const *argv[])
{
	int			*table;
	long long	i;
	int			start;
	int			end;


	if (argc == 3)
	{
		i = 0;
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		long long n = 0;
		if (start < end)
		{
			n = (long long)end - (long long)start;
		}
		else if (start > end)
		{
			n = (long long)start - (long long)end;
		}
		else
			n = 1;
		table = ft_range(start, end);

		i = 0;
		if (n != 1)
			while (i <= n)
			{
				printf("%d\n", table[i]);
				i++;
			}
		else
			printf("%d\n", table[0]);
		return (0);
	}
	else
		printf("error\n");
	return (0);
}
