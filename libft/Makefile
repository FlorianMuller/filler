# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 17:11:29 by fmuller           #+#    #+#              #
#    Updated: 2017/09/19 16:15:28 by fmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################
##COMPILATION
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = 

####################
##SOURCES
include Makefile_libft_src

####################
##NAME
NAME = libft.a
EXEC = a

EXT = 0


all: $(NAME)

$(NAME): $(LIBFT_OBJ)
	@ar rc $@ $^
	@echo "✅  "$(NAME)" created"

$(EXEC): main.o $(NAME)
	@$(CC) $(LDFLAGS) -L. -lft -o $@ $<

%.o: %.c $(LIBFT_HEADERS)
	@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean fclean re

clean:
	@rm -f $(LIBFT_OBJ)
ifeq ($(EXT),0)
	@echo "❌  object file removed"
endif

fclean: clean
	@rm -f $(NAME) $(EXEC)
	@echo "❌  $(NAME) removed"

re: fclean all
