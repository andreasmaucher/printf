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

NAME = ft_printf.a

SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
