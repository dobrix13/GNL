/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:56 by avitolin          #+#    #+#             */
/*   Updated: 2021/10/30 05:11:20 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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

static void ft_free_pointer(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char *ft_get_line(char **back, char **line)
{
	char *new_backup;
	int i;

	i = 0;
	new_backup = NULL;
	while (*(*back + i) != '\n' && *(*back +i) != '\0')
		i++;
	if (*(*back + i) == '\n')
	{
		i++;
		*line = ft_substr(*back, 0, i);
		new_backup = ft_strdup(*back + i);
	}
	else
		*line = ft_strdup(*back);
	ft_free_pointer(back);
	return (new_backup);
}

static int ft_read_line(int fd, char **buff, char **back, char **line)
{
	int bytes_read;
	char *temp_ptr;


printf("DEBUG ft read line \n");

	bytes_read = 1;
	while (!ft_strchr(*back, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buff, BUFFER_SIZE);
		*buff[bytes_read] = '\0';
		temp_ptr = *back;
		*back = ft_strjoin(temp_ptr, *buff);
		free (temp_ptr);
	}
	ft_free_pointer(buff);
	*back = ft_get_line(back, line);
	if (!(**line))
		ft_free_pointer(line);
	return (bytes_read);
}

char *get_next_line(int fd)
{
	static char	*buffer_backup = NULL;
	char		*buffer;
	char		*line;

printf("DEBUG START \n");
printf("ft_get_next_line \n");

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return(NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd , buffer, 0) < 0)
	{
		free (buffer);
		return (NULL);
	}
	if (!buffer_backup)
		buffer_backup = ft_strdup("");
	if (!ft_read_line(fd, &buffer, &buffer_backup, &line) && !line)
		return (NULL);
	return (line);
}
