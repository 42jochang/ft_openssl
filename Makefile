# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/03 11:50:13 by jochang           #+#    #+#              #
#    Updated: 2018/08/09 16:24:48 by jochang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC = src/main.c \
	md5/md5.c \
	md5/md5_init.c \
	sha256/sha256.c \
	sha256/sha256_init.c \
	sha224/sha224.c \
	sha224/sha224_init.c \
	sha512/sha512.c \
	sha512/sha512_init.c \
	sha384/sha384.c \
	sha384/sha384_init.c \
	src/preprocessing.c \
	src/preprocessing_l.c \
	src/ft_getflags.c \
	src/display_messages.c \
	src/print_ssl.c \
	src/hash_opt.c \

OBJ = *.o

INC = inc

CFLAGS = -Wall -Wextra -Werror
LIBFT = -L ./libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(CFLAGS) -c $(SRC) -I $(INC)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)

re: fclean all

leaks:
	@gcc $(CFLAGS) -g $(SRC) $(LIBFT) -I $(INC)
