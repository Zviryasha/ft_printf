# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opanchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/09 12:58:56 by opanchen          #+#    #+#              #
#    Updated: 2017/04/30 17:34:59 by opanchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC =   check_o.c    \
		check_type.c \
		deo.c        \
		flag.c       \
		ft_olo.c     \
		ft_printf.c  \
		hash_o.c     \
		my_char.c    \
		my_hesh.c    \
		my_onio.c    \
		my_uoi.c     \
		star.c       \
		p_trans.c    \
		cent.c   \
		strings.c   \
		big_c.c     \
		big_s.c    \
		check_o_2.c \
		check_type_2.c  \
		check_type_3.c   \
		flag_1.c  \
		my_hesh_1.c  \
		my_hesh_2.c  \
		width_pre_1.c \
		width_pre.c   \
		ft_printf_1.c  \
		ft_printf_2.c   \
		ft_printf_3.c  \
		ft_printf_4.c  \
		ft_printf_5.c \
		ft_printf_6.c  \

HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	ar -cru $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)
%.o: %.c
	$(G) $(CFLAGS) -c -o $@ $<
clean:
	make clean -C ./libft
	$(DEL) $(OBJ)
fclean: clean
	make fclean -C ./libft
	$(DEL) $(NAME)
re: all
	make all -C ./libft
