#include "print_bits.c"
#include <stdio.h>


 #include <string.h>
 
 /* reverse:  переворачиваем строку s на месте */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 void itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

int		main(void)
{
	unsigned int x;
	char s[100];
	int i;
	
	i = 0;
	x = 0;
	while (x <= 255)
	{
		write(1, "x=", 2);
		itoa(x, s);
		i = 0;
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, " | ", 3);
		print_bits(x);

		x++;
		write(1, "\n", 1);
	}
	return (0);
}
