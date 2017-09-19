# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 00:59:16 by fmuller           #+#    #+#              #
#    Updated: 2017/09/19 17:45:17 by fmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
## LIBFT
#
include ../libft/Makefile_libft_src
LIBFT_PATH = ../$(LIBFT_DIR)
LIBFT = $(addprefix $(LIBFT_PATH)/,lib$(LIBFT_NAME).a)
LIBFT_PATH_SRC = $(addprefix $(LIBFT_PATH)/,$(LIBFT_SRC))
LIBFT_PATH_HEADERS = $(addprefix $(LIBFT_PATH)/,$(LIBFT_HEADERS))

########################################
## BACK TO THE FILLER
#

####################
## COMPILATION
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lncurses -L$(LIBFT_PATH) -l$(LIBFT_NAME)

####################
## SOURCES
include Makefile_btf_src

EXT = 0


all: $(BTF_NAME)

$(BTF_NAME): $(BTF_OBJ) $(LIBFT)
	@$(CC) -g $(LDFLAGS) $(BTF_OBJ) -o $@
	@cp backToTheFiller ..
	@echo "✅  $(BTF_NAME) created"

%.o: %.c $(BTF_HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_PATH_SRC) $(LIBFT_PATH_HEADERS)
	@$(MAKE) -C $(LIBFT_PATH)

.PHONY: clean fclean re

clean:
	@rm -rf $(BTF_OBJ)
ifeq ($(EXT),0)
	@$(MAKE) -C $(LIBFT_PATH) clean EXT=1
	@echo "❌  object files removed"
endif


fclean: clean
	@rm -rf $(BTF_NAME)
	@rm -rf ../backToTheFiller
ifeq ($(EXT),0)
	@$(MAKE) -C $(LIBFT_PATH) fclean EXT=1
endif
	@echo "❌  $(BTF_NAME) removed"

re: fclean all
