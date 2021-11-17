# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 10:50:41 by avitolin          #+#    #+#              #
#    Updated: 2021/11/17 00:30:59 by avitolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc main.c -g -Wall -Wextra -Werror -D BUFFER_SIZE=4222 get_next_line.c get_next_line_utils.c get_next_line.h -o gnl
./gnl
rm gnl
