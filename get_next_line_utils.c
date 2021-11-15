/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:28:21 by avitolin          #+#    #+#             */
/*   Updated: 2021/11/15 21:48:42 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strjoin(char const *str_1, char const *str_2)
{
	char	*return_string;
	int		str_1_len;
	int		str_2_len;
	int		i;
	int		j;

	str_1_len = ft_strlen(str_1);
	str_2_len = ft_strlen(str_2);
	return_string = malloc((str_1_len + str_2_len + 1) * sizeof(char));
	if (!return_string)
		return (0);
	i = -1;
	j = 0;
	while (++i < str_1_len)
		return_string[i] = str_1[i];
	i--;
	while (i++ < (str_1_len + str_2_len))
		return_string[i] = str_2[j++];
	return_string[i - 1] = '\0';
	free((void *)str_1);
	return (return_string);
}
