/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:29:02 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 12:50:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

static int error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int main(int ac, char **av)
{
	int i;
	int j;
	int a;
	int b;
	int res;
	int count;

	if (ac == 2)
	{
		if (valid_str(av[1]))
		{
			i = 0;
			res = 0;
			while(av[1][i])
			{
				while (av[1][i] != '+' && av[1][i] != '*' && av[1][i] != '/' &&
							av[1][i] != '%' && av[1][i])
				{
					if (av[1][i] == '-' && (av[1][i + 1] == ' ' || !(av[1][i + 1])))
						break ;
					i++;
				}
				j = i - 2;	
				if (av[1][j] >= '0' && av[1][j] <= '9')
				{
					while (av[1][j] != ' ' && j >= 0)
						j--;
					b = atoi(&av[1][j]);
					j--;
					if (av[1][j] >= '0' && av[1][j] <= '9')
					{
						while (av[1][j] != ' ' && j > 0)
							j--;
						a = atoi(&av[1][j]);
					}
					else
						a = res;
				}
				else
				{
					count = 1;
					while (av[1][j] == '+' || av[1][j] == '-' || av[1][j] == '*' ||
						av[1][j] == '/' || av[1][j] == '%' || av[1][j] == ' ')
					{
						if (av[1][j] == '+' || av[1][j] == '-' || av[1][j] == '*' ||
						av[1][j] == '/' || av[1][j] == '%')
							count++;
						j--;
					}
					b = res;
					while (count)
					{
						if (av[1][j] == ' ')
							count--;
						j--;
					}
					while (av[1][j] != ' ' && j > 0)
							j--;
						a = atoi(&av[1][j]);
				}
				if (av[1][i] == '+')
					res = ft_plus(a, b);
				else if (av[1][i] == '-')
					res = ft_minus(a, b);
				else if (av[1][i] == '*')
					res = ft_mult(a, b);
				else if (av[1][i] == '/')
				{
					if (b == 0)
						return (error());
					res = ft_div(a, b);
				}
				else if (av[1][i] == '%')
				{
					if (b == 0)
						return (error());
					res = ft_mod(a, b);
				}
				i++;
			}
			printf("%d\n", res);
		}
		else
			return (error());
	}
	else
	   return (error());	
	return (0);
}
