#include "ft_strcpy.c"
#include <stdio.h>
int	main(void)
{
	char dst[1];
	char src[6] = "Hello";
	printf("%s\n", ft_strcpy(dst, src));
	return (0);
}
