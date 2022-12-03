# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: therodri <therodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:53:58 by therodri          #+#    #+#              #
#    Updated: 2022/12/03 13:24:49 by therodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_printf ft_pf_print ft_pf_count ft_pf_simpleft\

SRCS_DIR = ./
BONUS_DIR = ./_bonus/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
BONUS_SRC = $(addprefix $(BONUS_DIR), $(addsuffix _bonus.c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(BONUS_DIR), $(addsuffix _bonus.o, $(FILES)))

LIBFT_DIR = libft/
LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	cp ${LIBFT_DIR}${LIBFT_NAME} $@
	${AR} $@ $^

$(OBJS): makelibft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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

bonus: $(OBJS_BONUS)
	cp ${LIBFT_DIR}${LIBFT_NAME} $(NAME)
	${AR} $(NAME) $^
	
$(OBJS_BONUS): fclean makelibft	

%_bonus.o: %_bonus.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY: all clean fclean re