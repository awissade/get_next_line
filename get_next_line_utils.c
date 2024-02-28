/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:34:24 by awissade          #+#    #+#             */
/*   Updated: 2024/01/11 16:59:46 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	i;
	char	*new_line;
	int		j;

	if (!line)
	{
		line = (char *)malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	i = ft_strlen(line) + ft_strlen(buffer);
	new_line = (char *)malloc(i + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new_line[i++] = buffer[j++];
	new_line[i] = 0;
	free(line);
	return (new_line);
}

char	*ft_strchr(char *line, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	while (i <= len)
	{
		if (line[i] == (char)c)
			return ((char *)(line + i));
		i++;
	}
	return (NULL);
}
