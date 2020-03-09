# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 17:06:24 by mfrias            #+#    #+#              #
#    Updated: 2019/08/07 14:11:27 by mfrias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CFLAG	= -Wall -Wextra -Werror
SRC		= $(wildcard *.c)
OBJ		= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT: clean fclean $(NAME)
