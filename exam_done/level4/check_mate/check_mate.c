/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuzniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:28:22 by okuzniet          #+#    #+#             */
/*   Updated: 2018/01/19 18:28:25 by okuzniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				ft_opiece(char piece)
{
	if (piece == 'P' || piece == 'Q' || piece == 'B' || piece == 'R')
		return (1);
	return (0);
}

int				ft_pawn(char **board, int y, int x)
{
	if (y > 1)
	{
		if (x > 0 && board[y - 1][x - 1] == 'K')
			return (1);
		else if (x + 1 < ft_strlen(board[y]) && board[y - 1][x + 1] == 'K')
			return (1);
	}
	return (0);
}

int				ft_bishop(char **board, int y, int x)
{
	int			i;
	int			j;
	int			len;

	len = ft_strlen(board[y]);
	i = y;
	j = x;
	while (--i >= 1 && --j >= 0 && ft_opiece(board[i][j]) != 1) //Up Left
	{
		if (board[i][j] == 'K')
			return (1);
	}
	i = y;
	j = x;
	while (--i >= 1 && ++j < len && ft_opiece(board[i][j]) != 1) //Up Right
	{
		if (board[i][j] == 'K')
			return (1);
	}
	i = y;
	j = x;
	while (++i <= len && ++j < len && ft_opiece(board[i][j]) != 1) //Down Right
	{
		if (board[i][j] == 'K')
			return (1);
	}
	i = y;
	j = x;
	while (++i <= len && --j >= 0 && ft_opiece(board[i][j]) != 1) //Down Left
	{
		if (board[i][j] == 'K')
			return (1);
	}
	return (0);
}

int				ft_rook(char **board, int y, int x)
{
	int			i;
	int			j;
	int			len;

	j = x;
	len = ft_strlen(board[y]);
	while (++j < len && ft_opiece(board[y][j]) != 1) // Horzontal++
	{
		if (board[y][j] == 'K')
			return (1);
	}
	j = x;
	while (--j >= 0 && ft_opiece(board[y][j]) != 1) // Horzontal--
	{
		if (board[y][j] == 'K')
			return (1);
	}
	i = y;
	while (++i <= len && ft_opiece(board[i][x]) != 1) // Vertical++
	{
		if (board[i][x] == 'K')
			return (1);
	}
	i = y;
	while (--i >= 1 && ft_opiece(board[i][x]) != 1) // Vertical--
	{
		if (board[i][x] == 'K')
			return (1);
	}
	return (0);
}

static int		ft_checkmate(char **av)
{
	int			i;
	int			j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'P' && ft_pawn(av, i, j) == 1)
				return (1);
			if (av[i][j] == 'R' && ft_rook(av, i, j) == 1)
				return (1);
			if (av[i][j] == 'B' && ft_bishop(av, i, j) == 1)
				return (1);
			if (av[i][j] == 'Q' && (ft_rook(av, i, j) == 1 || ft_bishop(av, i, j) == 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	if (ac > 1 && (ft_strlen(av[1]) + 1) == ac)
	{
		int i;

		i = 1;
		while (av[i] != NULL)
		{
			if (ft_strlen(av[i]) + 1 == ac)
				i++;
			else
			{
				write(1, "Fail\n", 5);
				return (0);
			}
		}
		if (ft_checkmate(av) == 1)
			write(1, "Success\n", 8);
		else
			write(1, "Fail\n", 5);
	}
	else if (ac > 1)
		write(1, "Fail\n", 5);
	else
		write(1, "\n", 1);
	return (0);
}
