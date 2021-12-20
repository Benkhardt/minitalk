# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 17:58:34 by dbenkhar          #+#    #+#              #
#    Updated: 2021/12/20 16:10:58 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Note that the TIMEOUT has to be adjusted in some cases to make the communication
# work. It's the actual usleep() value in between the signals which'll be send to server.
# This TIMEOUT has been tested on 42Mac at School. It's also working on 
# Macbook Air with M1 chip (can be even shorter). WSL might be the worst in case
# of making it work, also other UNIX systems in general handling signa() different.
# So please feel free to test stuff but also keep this in mind. Thanks.

LIBFT = libft/libft.a

N_CLIENT = client
TIMEOUT = S_TIMEOUT=100

N_SERVER = server

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

all :
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(N_CLIENT).c $(LIBFT) -o $(N_CLIENT) -D $(TIMEOUT)
	$(CC) $(FLAGS) $(N_SERVER).c $(LIBFT) -o $(N_SERVER)

clean :
	$(MAKE) clean -C ./libft

fclean :
	$(MAKE) fclean -C ./libft
	$(RM) $(N_CLIENT) $(N_SERVER)

re : fclean all