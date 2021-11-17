/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:31:05 by avitolin          #+#    #+#             */
/*   Updated: 2021/11/17 00:25:39 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*gnl_read_to_tmp(int fd, char *temp_line);
size_t		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*gnl_linejoin(char *temp_line, char *buffer);
char	*gnl_get_line(char *temp_line);
char *gnl_read_on(char *temp_line);

#endif
