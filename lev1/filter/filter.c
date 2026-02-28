/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:08:04 by habe              #+#    #+#             */
/*   Updated: 2026/02/28 14:23:47 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUF_SIZE
# define BUF_SIZE 100
#endif

char	*read_stdin(void)
{
	char	*src;
	size_t	total_size;
	size_t	read_size;

	src = NULL;
	total_size = 0;
	while (1)
	{
		src = realloc(src, total_size + BUF_SIZE + 1);
		if (src == NULL)
			return (NULL);
		read_size = read(0, src + total_size, BUF_SIZE);
		if (read_size == 0)
			break ;
		if (read_size < 0)
			return (NULL);
		total_size += read_size;
	}
	src[total_size] = '\0';
	return (src);
}

void	filter_src(char *src, char *key, size_t key_len)
{
	char	*tmp;
	size_t	i;

	while (1)
	{
		i = 0;
		tmp = memmem(tmp, strlen(tmp), key, key_len);
		if (tmp == NULL || *tmp == '\0')
			break ;
		while (i < key_len)
		{
			tmp[i] = '*';
			i++;
		}
		tmp += key_len;
	}
}

int	main(int ac, char **av)
{
	char	*src;

	if (ac != 2 || av[1][0] == '\0')
		return (write(1, "ERROR\n", 6), 1);
	src = read_stdin();
	if (src == NULL)
		return (perror("ERROR"), 1);
	filter_src(src, av[1], strlen(av[1]));
	printf("%s", src);
	free(src);
	return (0);
}
