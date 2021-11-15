/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/04 14:29:32 by avitolin		  #+#	#+#			 */
/*   Updated: 2021/11/15 19:57:21 by avitolin		 ###   ########.fr	   */
/*																			*/
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

#include "get_next_line.h"

int	has_new_line(char *string)
{
	int		i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	int		len;
	char	*line;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	line = malloc((len + 2) * sizeof(char));
	ft_strlcpy(line, str, len + 2);
	return (line);
}

char	*get_remain(char *str)
{
	int		i;
	int		len;
	char	*remain;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	len = ft_strlen(str) - i;
	remain = malloc((len + 1) * sizeof(char));
	ft_strlcpy(remain, str + i + 1, len + 1);
	free(str);
	return (remain);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	char		*line;
	int			size;

	while (!has_new_line(save))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		if (size == 0)
			return (NULL);
		buffer[size] = 0;
		save = ft_strjoin(save, buffer);
	}
	line = get_line(save);
	save = get_remain(save);
	printf("%ld", sizeof(buffer));
	return (line);
}
