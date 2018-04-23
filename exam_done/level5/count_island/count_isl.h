/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_isl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:10:23 by exam              #+#    #+#             */
/*   Updated: 2017/11/28 12:27:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_ISL_H
# define COUNT_ISL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	print_str(char **str);
void	count_island(char **str);
int		check_file(char **str);

#endif
