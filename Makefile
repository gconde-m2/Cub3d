# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gconde-m <gconde-m@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 09:31:09 by gconde-m          #+#    #+#              #
#    Updated: 2020/06/03 06:56:31 by gconde-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  \
ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c  ft_split.c  \
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c  \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c  \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_printf.c ft_readinglast.c
SRCGNL = get_next_line.c getnextline/get_next_line_utils.c
SRCCUB = cub3d.c ft_zero.c ft_move.c ft_sprites.c ft_floor.c ft_wall.c ft_sprite2.c ft_reading.c ft_errorsexit.c ft_reading2.c bmp.c ft_readinglast.c
CC = gcc -Wall -Wextra -Werror
RM = rm -f
all: $(NAME)
$(NAME): 
	${CC} libft/libft.a getnextline/${SRCGNL} minilibx/libmlx.a ${SRCCUB} -framework OpenGL -framework AppKit -o CUB3D
bonus:
	${CC} libft/libft.a getnextline/${SRCGNL} minilibx/libmlx.a ${SRCCUB} -framework OpenGL -framework AppKit -o CUB3D
debug:
	${CC} libft/libft.a getnextline/${SRCGNL} minilibx/libmlx.a ${SRCCUB}	-framework OpenGL	-framework AppKit	-g	-o	CUB3D
fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
clean:
	${RM} ${OBJ} ${OBJBONUS}
re: fclean all
.PHONY: all clean fclean re bonus
