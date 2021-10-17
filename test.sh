# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 10:50:41 by avitolin          #+#    #+#              #
#    Updated: 2021/10/16 15:00:09 by avitolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc main.c -g -Wall -Wextra -Werror -D BUFFER_SIZE=0 get_next_line.c get_next_line_utils.c -o gnl
./gnl tests/text | cat -e
rm gnl
