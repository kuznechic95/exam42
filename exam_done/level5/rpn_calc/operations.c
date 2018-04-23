/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:19:20 by exam              #+#    #+#             */
/*   Updated: 2017/12/05 11:33:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int ft_plus(int a, int b)
{
	return (a + b);
}

int ft_minus(int a, int b)
{
	return (a - b);
}

int ft_mult(int a, int b)
{
	return (a * b);
}

int ft_div(int a, int b)
{
	return (a / b);
}

int ft_mod(int a, int b)
{
	return (a % b);
}
