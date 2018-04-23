#include "sort_int_tab.c"
#include "../../level3/ft_range/ft_range.c"

int main(void)
{
	int i;
	int *ar;

	i = 0;
	ar = ft_range(10, -10);
	sort_int_tab(ar, 21);
	while (i <= 20)
	{
		printf("%d\n", ar[i]);
		i++;
	}
	return (0);
}