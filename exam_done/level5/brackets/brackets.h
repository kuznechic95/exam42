/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:19:32 by ovirchen          #+#    #+#             */
/*   Updated: 2017/12/04 15:19:40 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# include <unistd.h>
# include <stdio.h>

int ft_round_brackets(char *str, int *i);
int ft_square_brackets(char *str, int *i);
int ft_figure_brackets(char *str, int *i);

#endif
