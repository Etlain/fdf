# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/02/26 15:02:32 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libft/libft.a

SRC = main.c draw_line.c draw_map.c read_map.c

PATH_SRC = sources/

FLAGS = -Wall -Wextra -Werror

LIBFT = -C libft/

MINILIB = -C minilibx_macos/

ML = minilibx_macos/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

all: 
	make $(LIBFT)
	make $(MINILIB)
	gcc -o $(NAME) $(addprefix $(PATH_SRC), $(SRC)) $(LIB) $(ML) $(FRAMEWORK)

clean :
	make clean $(LIBFT)
	make clean $(MINILIB)

fclean:
	make fclean $(LIBFT)
	make clean $(MINILIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
