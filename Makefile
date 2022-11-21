# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: therodri <therodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:53:58 by therodri          #+#    #+#              #
#    Updated: 2022/11/21 22:22:07 by therodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_printf ft_pf_print ft_pf_count ft_pf_simpleft\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = libft2/
LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	cp ${LIBFT_DIR}${LIBFT_NAME} $@
	${AR} $@ $^

$(OBJS): makelibft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

makelibft:
	cd ${LIBFT_DIR} && make

fcleanlibft:
	cd ${LIBFT_DIR} && make fclean

all: $(NAME)

clean: fcleanlibft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: clean all

bonus:
	cp ${LIBFT_DIR}${LIBFT_NAME} $@
	${AR} $@ $<

.PHONY: all clean fclean re