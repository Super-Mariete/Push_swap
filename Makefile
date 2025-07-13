# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 18:41:33 by made-ped          #+#    #+#              #
#    Updated: 2025/07/12 00:50:11 by made-ped         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

NAME       = push_swap
SRC        = main.c\
		control_error.c\
		string_utils.c\
		create_list.c\
		swap_funtions.c\
		push_funtions.c\
		rotate_funtions.c\
		reverse_rotate_funtions.c
OBJ        = $(SRC:.c=.o)

LIBFT_DIR  = libft
LIBFT_A    = $(LIBFT_DIR)/libft.a
LIBFT_INC  = -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
