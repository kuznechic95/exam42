#include "swap_bits.c"
#include <stdio.h>

int		main(void)
{
	unsigned int x;
	unsigned int xbin;
	
	x = 0;
	while (x <= 255)
	{
		printf("x=%d\n", x);
		print_bits(x);

		xbin = swap_bits(x);
		print_bits(xbin);
		x++;
		write(1, "\n", 1);
	}
	return (0);
}
