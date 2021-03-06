/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:49:28 by avitolin          #+#    #+#             */
/*   Updated: 2021/11/17 00:29:47 by avitolin         ###   ########.fr       */
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
	int		fd;
	int		i;

	i = 0;
	fd = open("./test/file_2", O_RDONLY);
	system("clear");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("result %d: %s", i + 1, line);
		i++;
	}
	close(fd);
	printf("EOF: ===== BUFFER_SIZE = %d\n", BUFFER_SIZE);
	return (0);
}
