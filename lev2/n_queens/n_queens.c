/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:08:12 by habe              #+#    #+#             */
/*   Updated: 2026/02/28 10:39:52 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_valid(int *pos, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (pos[i] == col || pos[i] - col == i - row || pos[i] - col == row - i)
			return (1);
		i++;
	}
	return (0);
}

void	solve(int *pos, int row, int n)
{
	int	col;
	int	i;

	if (row == n)
	{
		i = 0;
		while (i < n)
		{
			if (i > 0)
				printf(" ");
			printf("%d", pos[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	col = 0;
	while (col < n)
	{
		if (is_valid(pos, row, col) != 1)
		{
			pos[row] = col;
			solve(pos, row + 1, n);
		}
		col++;
	}
	return ;
}

int	main(int ac, char *av[])
{
	int	n;
	int	*pos;

	if (ac != 2 || av[1][0] == '-')
		return (1);
	n = atoi(av[1]);
	pos = malloc(sizeof(int) * n);
	if (pos == NULL)
		return (1);
	solve(pos, 0, n);
	free(pos);
	return (0);
}
