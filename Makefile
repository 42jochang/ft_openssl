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
	src/preprocessing.c \
	src/preprocessing_l.c \
	src/ft_getflags.c \
	src/error_checks.c \
	src/display_messages.c \
	src/print_ssl.c \
	src/hash_opt.c \

MD = md5/md5.c \
	md5/md5_init.c \
	sha256/sha256.c \
	sha256/sha256_init.c \
	sha224/sha224.c \
	sha224/sha224_init.c \
	sha512/sha512.c \
	sha512/sha512_init.c \
	sha384/sha384.c \
	sha384/sha384_init.c \

INC = inc

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\033[32mmaking ft_ssl...\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MD) -I $(INC) $(LIBFT)

.PHONY: clean
clean:
	@make -C libft clean
	@echo "\033[33mcleaning repository...\033[0m"

.PHONY: fclean
fclean: clean
		@make -C libft fclean
		@echo "\033[33mremoving executable...\033[0m"
		@rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: leaks
leaks:
	@echo "\033[32mmaking leak checker...\033[0m"
	@$(CC) $(CFLAGS) -g $(SRC) $(MD) $(LIBFT) -I $(INC)
