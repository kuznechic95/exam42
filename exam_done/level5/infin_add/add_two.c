/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:19:47 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 16:47:13 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

void	finish_res_add(char *res, char *num1, size_t max_len, int rem)
{
	int digit;

	while (max_len)
	{
		digit = GETNUM(num1[max_len - 1]) + rem;
		rem = digit / 10;
		digit = digit % 10;
		res[max_len] = GETCHARNUM(digit);
		max_len--;
	}
	if (rem)
		res[0] = GETCHARNUM(rem);
}

void	add(char *num1, char *num2, size_t max_len, size_t min_len)
{
	char	*res;
	int		digit;
	int		rem;

	res = get_zero_str(max_len + 1);
	rem = 0;
	while (min_len)
	{
		digit = GETNUM(num1[max_len - 1]) + GETNUM(num2[min_len - 1]) + rem;
		rem = digit / 10;
		digit = digit % 10;
		res[max_len] = GETCHARNUM(digit);
		max_len--;
		min_len--;
	}
	finish_res_add(res, num1, max_len ,rem);
	skip_zeros(&res);
	write(1, res, ft_strlen(res));
	write(1, "\n", 1);
}

void	finish_res_sub(char *res, char *num1, size_t max_len, int rem)
{
	int digit;

	while (max_len)
	{
		digit = GETNUM(num1[max_len - 1]) + rem;
		if (digit < 0)
		{
			digit = 9;
			rem = -1;
		}
		else
			rem = 0;
		res[max_len] = GETCHARNUM(digit);
		max_len--;
	}
}

void	sub(char *num1, char *num2, size_t max_len, size_t min_len)
{
	char	*res;
	int		digit;
	int		rem;
	int		temp;

	res = get_zero_str(max_len + 1);
	rem = 0;
	while (min_len)
	{
		digit = GETNUM(num1[max_len - 1]) - GETNUM(num2[min_len - 1]) + rem;
		if (digit < 0)
		{
			temp = rem;
			rem = -1;
			digit = 10 + GETNUM(num1[max_len - 1]) - GETNUM(num2[min_len - 1]) + temp;
		}
		else
			rem = 0;
		res[max_len] = GETCHARNUM(digit);
		max_len--;
		min_len--;
	}
	finish_res_sub(res, num1, max_len, rem);
	skip_zeros(&res);
	write(1, res, ft_strlen(res));
	write(1, "\n", 1);
}

void	add_two(char *num1, char *num2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(num1);
	len2 = ft_strlen(num2);
	if (*num1 == '-' && *num2 == '-')
	{
		write(1, "-", 1);
		num1++;
		num2++;
		len1--;
		len2--;
		if (len1 > len2)
			add(num1, num2, len1, len2);
		else
			add(num2, num1, len2, len1);
	}
	else if (*num1 == '-' && *num2 != '-')
	{
		num1++;
		len1--;
		if (more(num1, num2, len1, len2))
		{
			write(1, "-", 1);
			sub(num1, num2, len1, len2);
		}
		else
			sub(num2, num1, len2, len1);
	}
	else if (*num2 == '-' && *num1 != '-')
	{
		num2++;
		len2--;
		if (more(num2, num1, len2, len1))
		{
			write(1, "-", 1);
			sub(num2, num1, len2, len1);
		}
		else
			sub(num1, num2, len1, len2);
	}
	else
	{
		if (len1 > len2)
			add(num1, num2, len1, len2);
		else
			add(num2, num1, len2, len1);
	}
}
