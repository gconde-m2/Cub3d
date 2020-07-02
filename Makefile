# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gconde-m <gconde-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 09:31:09 by gconde-m          #+#    #+#              #
#    Updated: 2020/06/08 13:09:27 by gconde-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS   = $(shell uname)
NAME = cub3d

ifeq ($(OS), Linux)
	MLXDIR  = ./minilibx-linux
	MLX_LNK = -l mlx -lXext -lX11 -lm -lbsd
else
	MLXDIR  = ./minilibx
	MLX_LNK = -l mlx -framework OpenGL -framework AppKit
endif

SRCGNL = get_next_line.c getnextline/get_next_line_utils.c
SRCCUB = cub3d.c ft_zero.c ft_move.c ft_sprites.c ft_floor.c ft_wall.c ft_sprite2.c ft_reading.c ft_errorsexit.c ft_reading2.c bmp.c ft_readinglast.c
CC = gcc -Wall -Wextra -Werror -g 
OBJS	= $(SRCCUB:.c=.o)
FT := libft.a
FT_DIR := libft/
FT_LIB := -I $(FT_DIR) -L $(FT_DIR) -l ft
RM = rm -f
MLX_LNK += -L $(MLXDIR)
MLX_INC = -I $(MLXDIR)
MLX_LIB = $(addprefix $(MLX)/,mlx.a)
all: $(NAME)
%.o:%.c
	$(CC) -c $< -o $@
$(NAME):	$(OBJS)
	$(MAKE) -C libft/
	$(MAKE) -C $(MLXDIR)
	${CC}  $(OBJS) ${FT_LIB} ${MLX_LNK} -o $(NAME)
debug:
	 ${CC} $(OBJS) ${FT_LIB} ${MLX_LNK} -o $(NAME) 
fclean:
	${RM} ${NAME} ${OBJS}
	${RM} ${NAME} ${OBJBONUS}
clean:
	${RM} ${OBJ} ${OBJBONUS}
re: fclean all
.PHONY: clean fclean re
