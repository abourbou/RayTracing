# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/11 11:01:57 by abourbou     #+#   ##    ##    #+#        #
#    Updated: 2020/01/22 14:36:45 by abourbou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#VARIABLE

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC 		=	ft_atoi.c  ft_strdup.c ft_bzero.c \
				ft_strjoin.c ft_calloc.c ft_strlcat.c ft_isalnum.c \
	 			ft_memccpy.c ft_strlcpy.c ft_isalpha.c ft_memchr.c \
   				ft_strlen.c ft_isascii.c ft_memcmp.c ft_strmapi.c \
				ft_isdigit.c ft_memcpy.c ft_strncmp.c ft_isprint.c \
	 			ft_memmove.c ft_strnstr.c ft_itoa.c ft_memset.c \
				ft_strrchr.c  ft_putchar_fd.c ft_strtrim.c  ft_putendl_fd.c \
				ft_substr.c  ft_putnbr_fd.c ft_tolower.c  ft_putstr_fd.c \
				ft_toupper.c  ft_split.c ft_strchr.c \
				get_next_line.c get_next_line_utils.c \
				ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
				ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
				ft_lstlast_bonus.c is_in.c ft_strcmp.c

NAME		=	libft.a

RM 			= 	rm -f

INCL 		=	libft.h get_next_line.h

OBJ			= 	$(SRC:.c=.o)

#RULES

all 		:	$(OBJ) $(NAME)

$(NAME) 	:	$(OBJ)
				ar r $(NAME) $(OBJ)
				ranlib $(NAME)

%.o 		:	%.c $(INCL)
				$(CC) -c -o $@ $< $(CFLAGS)

clean 		:
				$(RM) $(OBJ)

fclean 		: 	clean
				$(RM) $(NAME)

re 			: 	fclean all

norm 		:	$(SRC)
				norminette $(SRC)  $(INCL)

.PHONY 		:	 clean fclean
