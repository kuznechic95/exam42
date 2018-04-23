/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:58:41 by okuzniet          #+#    #+#             */
/*   Updated: 2017/12/27 19:37:07 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_space(int x)
{
	return (x == ' ' || x == '\f' || x == '\r' || x == '\n' || \
		x == '\t' || x == '\v');
}

int		ft_is_digit(char x)
{
	return (x >= '0' && x <= '9');
}

int		ft_atoi(const char *str)
{
	unsigned int	num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_is_digit(*str))
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	return ((int)num * sign);
}
