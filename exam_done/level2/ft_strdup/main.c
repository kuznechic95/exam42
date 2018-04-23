#include "ft_strdup.c"
#include <stdio.h>

int		main(void)
{
	char *s = "hello!";
	char *s2;

	s2 = ft_strdup(s);

	printf("%s\n", s2);
}
