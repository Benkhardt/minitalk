# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 17:58:34 by dbenkhar          #+#    #+#              #
#    Updated: 2021/12/20 11:30:45 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

N_CLIENT = client
N_SERVER = server

CC = gcc

FLAGS = -Wall -Wextra -Werror



all :
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(N_CLIENT).c $(LIBFT) -o $(N_CLIENT)
	$(CC) $(FLAGS) $(N_SERVER).c $(LIBFT) -o $(N_SERVER)
