/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:20:40 by awissade          #+#    #+#             */
/*   Updated: 2024/01/13 13:11:15 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readed_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	size_readed;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size_readed = 1;
	while (size_readed > 0 && !ft_strchr(line, '\n'))
	{
		size_readed = read(fd, buffer, BUFFER_SIZE);
		if (size_readed == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[size_readed] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	free(buffer);
	return (line);
}

char	*returned_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*remainder_line(char *line)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	rem = (char *)malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!rem)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		rem[j++] = line[i++];
	rem[j] = '\0';
	free(line);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*line[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = readed_line(line[fd], fd);
	if (!line[fd])
		return (NULL);
	new_line = returned_line(line[fd]);
	line[fd] = remainder_line(line[fd]);
	if (!line[fd])
		free(line[fd]);
	return (new_line);
}
