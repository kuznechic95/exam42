
#include <stdlib.h>

int					*ft_range_up(int start, int end) {
	int				*tab;
	long long		n;
	long long		i;

	n = (long long)end - (long long)start;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))
		return (NULL);
	i = 0;
	while ((long long)start + i <= (long long)end)
	{
		tab[i] = start + i;
		i++;
	}
	return (tab);
}

int					*ft_range_down(int start, int end)
{
	int				*tab;
	long long		n;
	long long		i;

	n = (long long)end - (long long)start;
	if (!(tab = (int *)malloc(sizeof(int) * (n + 1))))
		return (NULL);
	i = 0;
	while ((long long)start <= (long long)end - i)
	{
		tab[i] = end - i;
		i++;
	}
	return (tab);
}

int			*ft_rrange(int start, int end)
{
	if (start < end)
		return (ft_range_down(start, end));
	return (ft_range_up(end, start));
}