/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:49:28 by avitolin          #+#    #+#             */
/*   Updated: 2021/10/30 05:06:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *result;

    fd = open("tests/text", O_RDWR);
    printf("fd:    %d\n", fd);
    printf("\n---start attempt-------------------------\n");
    result = get_next_line(fd);
    printf("result:    %s\n", result);
    printf("---end attempt----------------------------\n\n");
    while (result != NULL)
    {
        printf("\n---start attempt-------------------------\n");
        result = get_next_line(fd);
        printf("result:    %s\n", result);
        printf("---end attempt----------------------------\n\n");
    }

    
    return (0);
}
