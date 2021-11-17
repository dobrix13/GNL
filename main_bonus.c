/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:49:28 by avitolin          #+#    #+#             */
/*   Updated: 2021/11/17 01:19:14 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("./test/file_1", O_RDONLY);
	fd2 = open("./test/file_2", O_RDONLY);
	i = 1;
	while (i)
	{
		i = 0;
		line = get_next_line(fd1);
		if (line != NULL)
			i = printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		if (line != NULL)
			i = printf("line [%02d]: %s", i, line);
		free(line);
	}
	printf("End Of all Files reached. ===BUFFER_SIZE = %d\n", BUFFER_SIZE);
	close(fd1);
	close(fd2);
	return (0);
}
