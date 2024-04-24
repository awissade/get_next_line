/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:26:31 by awissade          #+#    #+#             */
/*   Updated: 2024/04/24 20:44:32 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *line, char *buffer);
char	*gnl_strchr(char *line, int c);

#endif
