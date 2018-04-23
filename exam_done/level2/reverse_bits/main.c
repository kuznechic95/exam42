#include "reverse_bits.c"
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

		print_bits(reverse_bits(x));
		print_bits(reverse_bits2(x));
		x++;
		xbin = reverse_bits(x);
	//	printf(" %d ", bin_to_uchar(reverse_bits(x)));
		write(1, "\n", 1);
	}
	return (0);
}
