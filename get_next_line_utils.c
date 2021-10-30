/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 04:04:59 by avitolin          #+#    #+#             */
/*   Updated: 2021/10/30 05:05:26 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Allocates (with malloc(3)) and returns a substring
**	from the string ’s’.
**	The substring begins at index ’start’ and is of
**	maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = *(s + start + i);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*	The strlen() function calculates the length of the string pointed to by s,
**	excluding the terminating null byte ('\0').
*/
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*	The strdup() function returns a pointer to a new string which
**	is a duplicate of the string s. Memory for the new string is
**	obtained with malloc(3), and can be freed with free(3).
*/
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	ptr = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	else
		ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
/*	The strlcpy() function copy strings 
**	Also note that strlcpy() 
**	only operate on true ''C'' strings. This means that for 
**	strlcpy() src must be NUL-terminated
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*	The	strchr() function returns a pointer to the first occurrence of the
**	character c in the string s.
*/
char	*ft_strchr(const char *s, int c)
{
	char	*return_str;

	return_str = (char *)s;
	while (*return_str != c)
	{
		if (*return_str == '\0')
		{
			return (NULL);
		}
		return_str++;
	}
	return (return_str);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(&str[s1_len], s2, s1_len + s2_len + 1);
	return (str);
}
