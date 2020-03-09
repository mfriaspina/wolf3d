# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrias <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 13:34:58 by mfrias            #+#    #+#              #
#    Updated: 2020/03/08 17:34:18 by mfrias           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
COMP = wolf3d.a

SRC := $(wildcard srcs/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
FILE = srcs/*.c

CFLAG = -Wall -Wextra -Werror
LIBS = -L mlx -lmlx -lpthread
FRAMEWORKS = -framework OpenGL -framework AppKit
HEADER = -I includes -I mlx

SUBDIR = libft/
ARCHIVE = libft.a

all: $(ARCHIVE) $(NAME)

$(NAME):
	gcc $(CFLAG) $(SRC) $(HEADER) $(COMP) $(LIBS) $(FRAMEWORKS) -o $(NAME)

$(ARCHIVE): $(OBJ)
	make -C $(SUBDIR)
	cp $(SUBDIR)$(ARCHIVE) .
	mv $(ARCHIVE) $(COMP)
	ar rc $(COMP) srcs/*.o
	ranlib $(COMP)

$(OBJ): srcs/%.o : srcs/%.c
	gcc $(CFLAG) $(HEADER) -c $< -o $@	

clean:
	rm -rf srcs/*.o
	make -C $(SUBDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(COMP)
	make -C $(SUBDIR) fclean

.SILENT: clean fclean $(NAME) $(ARCHIVE) $(OBJ)
re: fclean all
