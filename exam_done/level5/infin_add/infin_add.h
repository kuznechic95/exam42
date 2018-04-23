/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:18:27 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 15:54:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_ADD_H
#define INFIN_ADD_H

#include <unistd.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)
#define GETNUM(x) (x - '0')
#define GETCHARNUM(x) (x + '0')
#define ABS(x) (x > 0 ? x : -x)

void	add_two(char *num1, char *num2);
size_t	ft_strlen(char *str);
char	*get_zero_str(size_t size);
void	skip_zeros(char **str);
int		more(char *num1, char *num2, size_t len1, size_t len2);

#endif
