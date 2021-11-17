/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:28:21 by avitolin          #+#    #+#             */
/*   Updated: 2021/11/17 02:15:39 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_linejoin(char *temp_line, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!temp_line)
	{
		temp_line = (char *)malloc(1 * sizeof(char));
		temp_line[0] = '\0';
	}
	if (!temp_line || !buffer)
		return (NULL);
	line = malloc(sizeof(char) * ((ft_strlen(temp_line) + ft_strlen(buffer)) \
	+ 1));
	if (!line)
		return (NULL);
	if (temp_line)
		while (temp_line[++i] != '\0')
			line[i] = temp_line[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[i] = '\0';
	free(temp_line);
	return (line);
}

char	*gnl_get_line(char *temp_line)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!temp_line[i])
		return (NULL);
	while (temp_line[i] != '\n' && temp_line[i])
		i++;
	line = malloc((i + 2) * (sizeof (char)));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = temp_line[j];
		j++;
	}
	if (temp_line[j] == '\n')
	{
		line[j] = temp_line[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*gnl_read_on(char *temp_line)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (temp_line[i] != '\n' && temp_line[i])
		i++;
	if (!temp_line[i])
	{
		free (temp_line);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(temp_line) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (temp_line[i])
		line[j++] = temp_line[i++];
	line[j] = '\0';
	free (temp_line);
	return (line);
	free(line);
}
