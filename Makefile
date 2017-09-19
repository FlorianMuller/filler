# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/11 18:12:52 by fmuller           #+#    #+#              #
#    Updated: 2017/09/19 17:27:22 by fmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
## LIBFT
#
include libft/Makefile_libft_src
LIBFT = $(addprefix $(LIBFT_DIR)/,lib$(LIBFT_NAME).a)
LIBFT_DIR_SRC = $(addprefix $(LIBFT_DIR)/,$(LIBFT_SRC))
LIBFT_DIR_HEADERS = $(addprefix $(LIBFT_DIR)/,$(LIBFT_HEADERS))

########################################
## BACK TO THE FILLER
#
include btf/Makefile_btf_src
BTF = $(addprefix $(BTF_DIR)/,$(BTF_NAME))
BTF_DIR_SRC = $(addprefix $(BTF_DIR)/,$(BTF_SRC))
BTF_DIR_HEADERS = $(addprefix $(BTF_DIR)/,$(BTF_HEADERS))


########################################
## FILLER
#

####################
## COMPILATION
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -l$(LIBFT_NAME)

####################
## SOURCES
SRC =  main.c get_all.c resize_token.c find_pos.c get_closer.c surround.c complete.c
OBJ = $(SRC:.c=.o)
HEADERS = filler.h $(LIBFT_DIR_HEADERS)

####################
## NAME
NAME = fmuller.filler

.PHONY: Filler BTF Libft

all: Filler BTF

Filler: $(NAME)

BTF: $(BTF)

Libft: $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(LDFLAGS) -o $@ $(OBJ)
	@echo "✅  $(NAME) created"

$(BTF): $(BTF_DIR_SRC) $(BTF_DIR_HEADERS) $(LIBFT)
	@$(MAKE) -C $(BTF_DIR) 

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT): $(LIBFT_DIR_SRC) $(LIBFT_DIR_HEADERS)
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) $@ EXT=1
	@$(MAKE) -C $(BTF_DIR) $@ EXT=1
	@echo "❌  object files removed"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) $@ EXT=1
	@$(MAKE) -C $(BTF_DIR) $@ EXT=1
	@echo "❌  $(NAME) removed"

re: fclean all
