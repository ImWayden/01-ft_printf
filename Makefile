# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: therodri <therodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 09:46:49 by hlesny            #+#    #+#              #
#    Updated: 2022/11/21 07:21:04 by therodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_pf_simpleft.c ft_pf_print.c ft_pf_count.c
OBJECTS = $(SRC:.c=.o)
LIBFT_OBJECTS = libft2/$(LIBFTOBJ)
LIBFTSRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c ft_putstr_fd.c ft_strlcpy.c ft_memcmp.c ft_isalpha.c
	ft_lstlast.c ft_lstdelone.c ft_lstadd_back.c ft_lstsize.c ft_lstnew.c ft_lstadd_front.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c
LIBFT_PATH = libft2/
LIBFTOBJ = $(LIBFTSRC:.c=.o)
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
	make -C libft2/ clean
fclean: clean
	rm -f $(NAME)
	rm -f ./libft2/libft.a
re: fclean all

.PHONY: all bonus libft clean fclean re compile
