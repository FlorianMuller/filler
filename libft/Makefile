# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 17:11:29 by fmuller           #+#    #+#              #
#    Updated: 2017/05/17 18:54:43 by fmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = 
NAME = libft.a
OBJ = $(LIBFT_SRC_NAME:.c=.o)
EXEC = a
# SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c  ft_memmove.c ft_memchr.c ft_memcmp.c \
# ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strlcat.c \
# ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
# ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
# ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
# ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
# ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
# ft_lstlen.c ft_put_ntabs.c ft_put_tabs.c ft_tabslen.c ft_tabilen.c ft_put_ntabi.c ft_put_tabi.c \
# ft_realloc.c ft_itoa_base.c ft_unsigned_itoa_base.c ft_strcountc.c ft_wcslen.c \
# ft_str_insert.c ft_print_bit.c ft_ncpy_bit.c ft_read_bit.c ft_set_bit.c ft_init_pbit.c ft_wc_size.c \
# ft_wcs_conv_len.c ft_wc_to_cs.c ft_wcs_to_cs.c ft_wc_strsub.c ft_wc_strncpy.c ft_tabc_del.c get_next_line.c \
# ft_printf/param.c ft_printf/output.c ft_printf/init_all.c ft_printf/is_something.c ft_printf/read.c \
# ft_printf/read_params.c ft_printf/read_params2.c ft_printf/write_string.c ft_printf/write_char.c \
# ft_printf/write_nbr.c ft_printf/write_other.c ft_printf/write_all.c ft_printf/write_all2.c \
# ft_printf/ft_printf_fd.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@echo "✅  "$(NAME)" created"

$(EXEC): main.o $(NAME)
	@$(CC) $(LDFLAGS) -L. -lft -o $@ $<

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(EXEC)
	@echo "❌  $(NAME) removed"

re: fclean all
