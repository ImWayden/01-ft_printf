# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: therodri <therodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 20:56:08 by therodri          #+#    #+#              #
#    Updated: 2022/11/19 22:44:30 by therodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
MAIN = main.c
CFLAGS = -c -Wall -Werror -Wextra -I.
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c ft_putstr_fd.c ft_strlcpy.c ft_memcmp.c ft_isalpha.c
BONUS = ft_lstlast.c ft_lstdelone.c ft_lstadd_back.c ft_lstsize.c ft_lstnew.c ft_lstadd_front.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)
CC = gcc

all:$(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
	
$(NAME): base
	ar rc $(NAME) $(OBJ)
base:
	$(CC) $(CFLAGS) $(SRC) 
bonus : fclean base suffix
	ar rc $(NAME) $(OBJ) $(BONUSOBJ) 
suffix: 
	$(CC) $(CFLAGS) $(BONUS)	
clean :
	/bin/rm -f $(OBJ) $(BONUSOBJ) 
fclean : clean
	/bin/rm -f $(NAME)

re:	fclean all
	
