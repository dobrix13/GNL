/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:11:07 by avitolin          #+#    #+#             */
/*   Updated: 2021/11/16 22:36:35 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		FUNCTION NAME:
**	get_next_line
**
**		PROTOTYPE:
**	char *get_next_line(int fd);
**
**		TURN IN FILES:
**	get_next_line.c, get_next_line_utils.c, get_next_line.h
**
**		PAREMETERS:
**	File descriptor to read from
**
**		RETURN VALUE:
**	Read line: correct behavior
**	NULL: nothing else to read or an error occurred
**
**		EXTERNAL FUNCTIONS:
**	read, malloc, free
**
**		DESCRIPTION:
**	Write a function which returns a line read from a file descriptor
*/

#include "get_next_line_bonus.h"

char	*gnl_read_to_tmp(int fd, char *temp_line)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(temp_line, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		temp_line = gnl_linejoin(temp_line, buffer);
	}
	free(buffer);
	return (temp_line);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *temp_line[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp_line[fd] = gnl_read_to_tmp(fd, temp_line[fd]);
	if (!temp_line[fd])
		return (NULL);
	line = gnl_get_line(temp_line[fd]);
	temp_line[fd] = gnl_read_on(temp_line[fd]);
	return (line);
}
