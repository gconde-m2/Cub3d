# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 09:31:09 by gconde-m          #+#    #+#              #
#    Updated: 2019/11/19 10:34:42 by gconde-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_split.c \
		ft_lstiter.c \
		ft_lstmap.c \
		getnextline.c

DINCLUDE	= includes

INCLUDES	= ${DINCLUDE}/ft.h

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC 			= gcc

CFLAGS		 =  -I. -c

RM			 = rm -f

.c.o:		${INCLUDES}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}
BONUS:
	${INCLUDES}	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}
clean:
		${RM} ${OBJS}
fclean:		clean
		${RM} ${NAME}
re:			fclean all

.PHONY:	all clean fclean re
