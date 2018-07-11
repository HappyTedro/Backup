# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 12:37:57 by mcols             #+#    #+#              #
#    Updated: 2018/07/10 19:12:00 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ

SOURCES = srcs/display.c srcs/find_square.c srcs/store_file.c srcs/checkers.c srcs/main.c
INCLUDES = includes/bsq.h 
OBJECTS = srcs/gorgeous_input

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -O3 -o $(NAME) -I$(INCLDUES) $(SOURCES)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME)

re: fclean all 