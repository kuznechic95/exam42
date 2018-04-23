/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 21:26:29 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/10 21:26:30 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isblank(char c)
{
	return (c == ' ' || c == '\f' || c == '\r' || c == '\n' || c == '\t' \
					|| c == '\v');
}

int		ft_atoi_base(const char *str, int str_base)
{
	char basemin[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'a', 'b', 'c', 'd', 'e', 'f'};
	char basemax[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
						'A', 'B', 'C', 'D', 'E', 'F'};
	int i;
	int res;
	int neg;

	i = 0;
	res = 0;
	while (ft_isblank(str[i]))
		i++;
	neg = str[i] == '-';
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str_base <= 10)
	{
		while (str[i] && str[i] >= '0' && str[i] <= basemin[str_base - 1])
		{
			res *= str_base;
			res += str[i] - '0';
			i++;
		}
	}
	else if (str_base > 10)
	{
		while (str[i] && (str[i] >= '0' && (str[i] <= basemin[str_base - 1] || \
							str[i] <= basemax[str_base - 1])))
		{
			res *= str_base;
			if (str[i] >= '0' && str[i] <= '9')
				res += str[i] - '0';
			if (str[i] >= 'a' && str[i] <= 'f')
				res += str[i] - ('a' - 10);
			if (str[i] >= 'A' && str[i] <= 'F')
				res += str[i] - ('A' - 10);
			i++;
		}
	}
	if (neg && str_base = 10)
		res = -res;
	return (res);
}
