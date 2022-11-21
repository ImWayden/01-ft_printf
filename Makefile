# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: therodri <therodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 09:46:49 by hlesny            #+#    #+#              #
#    Updated: 2022/11/21 07:02:52 by therodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_pf_simpleft.c ft_pf_print.c ft_pf_count.c
OBJECTS = $(SRC:.c=.o)
LIBFT_OBJECTS = libft/*.o
LIBFT_PATH = libft/
AR = ar rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: re

$(NAME): compile libft 
	$(AR) $(NAME) $(OBJECTS) $(LIBFT_OBJECTS)
compile : libft
	$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $(SRC)
libft:
	make -C $(LIBFT_PATH) bonus
clean:
	rm -f $(OBJECTS)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
re: fclean all

.PHONY: all bonus libft clean fclean re compile
