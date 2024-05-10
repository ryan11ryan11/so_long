# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 17:03:39 by junhhong          #+#    #+#              #
#    Updated: 2024/05/08 19:42:25 by junhhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libft
LIBFT = libft/libft.a
NAME = so_long
AR = ar -rcs

SRC = so_long map map2

all : $(NAME)

SRCOBJ = $(addsuffix .o, $(SRC))

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(SRCOBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCOBJ) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(SRCOBJ)
	$(MAKE) -C ./libft fclean

fclean: clean
	rm -rf ${NAME}

re: fclean all

lib :
	$(MAKE) -C $(LIBDIR)/

libclean :
	$(MAKE) -C $(LIBDIR)/ clean

libfclean :
	$(MAKE) -C $(LIBDIR)/ fclean