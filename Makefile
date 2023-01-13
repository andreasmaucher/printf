# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 20:00:57 by amaucher          #+#    #+#              #
#    Updated: 2023/01/05 20:01:01 by amaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_hex.c ft_printf_itoa.c \
		ft_printf_uitoa.c ft_printf_words.c ft_printf_pointer.c \

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
