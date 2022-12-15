/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:01 by matde-je          #+#    #+#             */
/*   Updated: 2022/12/15 00:54:27 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			trig;
	int			j;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	trig = 0;
	while (trig == 0 && (buf[0] != '\0' || read(fd, buf, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buf);
		i = 0;
		j = 0;
		while (buf[i])
		{
			if (trig == 1)
				buf[j++] = buf[i];
			if (buf[i] == '\n')
				trig = 1;
			buf[i++] = 0;
		}
	}
	return (line);
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}