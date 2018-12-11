# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: struxill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 17:32:25 by struxill          #+#    #+#              #
#    Updated: 2018/12/11 20:27:48 by struxill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
NAME		= test_gnl
LIB			= libft/
INCLUDES	= libft/includes

SOURCES		= get_next_line.c 
OBJECTS		= $(SOURCES:.c=.o)
MAIN		= main.c
FIRST		= make -C $(LIB) fclean && make -C $(LIB)



all: $(NAME)

$(NAME):
	$(FIRST)	
	$(CC) $(CFLAGS) -I $(INCLUDES) -o get_next_line.o -c get_next_line.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o main.o -c main.c
	$(CC) -o $(NAME) main.o get_next_line.o -I $(INCLUDES) -L $(LIB) -lft
	
clean:
	rm -f $(OBJECTS) main.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
