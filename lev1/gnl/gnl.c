/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:08:08 by habe              #+#    #+#             */
/*   Updated: 2026/02/28 14:34:40 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#elif BUFFER_SIZE > 1
# undef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		i;

	line = malloc(100000);
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, BUFFER_SIZE) > 0)
	{
		line[i++] = c;
		if (c == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
