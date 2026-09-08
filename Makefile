# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 11:53:31 by dboldino          #+#    #+#              #
#    Updated: 2026/09/08 13:24:17 by dboldino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Werror -Wextra
RM	= rm -f

SRC_DIR	= srcs
TARGET	= libftprintf.a

SRCS	= $(SRC_DIR)/ft_printf.c \
		  $(SRC_DIR)/ft_print_utils.c

OBJS 	= $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

all:	$(TARGET)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(TARGET)

re:	fclean all

.PHONY: all clean fclean re
