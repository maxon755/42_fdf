#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayduk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 17:24:42 by mgayduk           #+#    #+#              #
#    Updated: 2018/01/09 10:16:51 by mgayduk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC 		:= gcc -Wall -Wextra -Werror -c

NAME 	:= libft.a


MEM_FUNCS := 	ft_memset.c 		\
				ft_bzero.c  		\
				ft_memcpy.c 		\
				ft_memccpy.c 		\
				ft_memmove.c 		\
				ft_memchr.c 		\
				ft_memcmp.c 		\
				ft_memalloc.c 		\
				ft_memdel.c 		\

STR_FUNCS :=	ft_strlen.c 		\
				ft_strdup.c 		\
				ft_strcpy.c 		\
				ft_strncpy.c 		\
				ft_strcat.c 		\
				ft_strncat.c 		\
				ft_strlcat.c 		\
				ft_strchr.c 		\
				ft_strrchr.c 		\
				ft_strstr.c 		\
				ft_strnstr.c 		\
				ft_strcmp.c 		\
				ft_strncmp.c 		\
				ft_strnew.c 		\
				ft_strdel.c 		\
				ft_strclr.c 		\
				ft_striter.c 		\
				ft_striteri.c 		\
				ft_strmap.c 		\
				ft_strmapi.c 		\
				ft_strequ.c 		\
				ft_strnequ.c 		\
				ft_strsub.c 		\
				ft_strjoin.c 		\
				ft_strtrim.c 		\
				ft_strsplit.c 		\

STR_ARR_FUNCS := ft_clear_strarr.c  \
				 ft_len_strarr.c	\
				 ft_put_strarr.c

CHAR_FUNCS := 	ft_isalpha.c 		\
				ft_isdigit.c 		\
				ft_isalnum.c 		\
				ft_isascii.c 		\
				ft_isprint.c 		\
				ft_toupper.c 		\
				ft_tolower.c 		\
				ft_iswhite.c

LIST_FUNCS :=	ft_lstnew.c 		\
				ft_lstdelone.c 		\
				ft_lstdel.c 		\
				ft_lstadd.c 		\
				ft_lstiter.c 		\
				ft_lstmap.c 		\
				ft_lstadd_back.c 	\
				ft_lstdel_back.c 	\
				ft_lstdel_front.c 	\
				ft_lstlen.c 		\
				ft_lst_erase.c

INT_FUNCS :=	ft_atoi.c 			\
				ft_atoi16.c			\
				ft_itoa.c 			\

RW_FUNCS = 		get_next_line.c 	\
				ft_putchar.c 		\
				ft_putstr.c 		\
				ft_putendl.c 		\
				ft_putnbr.c 		\
				ft_putchar_fd.c 	\
				ft_putstr_fd.c 		\
				ft_putendl_fd.c 	\
				ft_putnbr_fd.c



SRCS = $(MEM_FUNCS) $(STR_FUNCS) $(STR_ARR_FUNCS) $(CHAR_FUNCS) $(LIST_FUNCS) $(INT_FUNCS) $(RW_FUNCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all