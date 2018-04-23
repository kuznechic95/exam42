#include <stdio.h>
#include "ft_rrange.c"

int					main(void)
{
	int				*table;
	long long		i;
	int				start;
	int				end;

	start = -2147483640;
	end = -2147483648;

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
	table = ft_rrange(start, end);

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