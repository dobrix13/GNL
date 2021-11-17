# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 10:50:41 by avitolin          #+#    #+#              #
#    Updated: 2021/11/17 00:22:28 by avitolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc main_bonus.c -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h -o gnl
./gnl
rm gnl
