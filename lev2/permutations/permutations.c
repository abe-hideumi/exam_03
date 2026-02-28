/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:08:15 by habe              #+#    #+#             */
/*   Updated: 2026/02/28 14:20:35 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int	check_dup(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		j = i + 1;
		while (str[j] != '\0')
		{
			if (c == str[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_sort(char *str, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	permute(char *str, char *result, int *used, int len, int depth)
{
	int	i;


	if (depth == len)
	{
		result[len] = '\0';
		printf("%s\n", result);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			result[depth] = str[i];
			permute(str, result, used, len, depth + 1);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		len;
	char	*result;
	int		*used;

	if (ac != 2 || check_dup(av[1]) != 0)
		return (1);
	len = ft_strlen(av[1]);
	ft_sort(av[1], len);
	result = calloc(len + 1, sizeof(char));
	used = calloc(len, sizeof(int));
	if (!result || !used)
		return (1);
	permute(av[1], result, used, len, 0);
	free(result);
	free(used);
	return (0);
}
