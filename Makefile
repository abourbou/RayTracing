# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/14 10:41:55 by jotrique     #+#   ##    ##    #+#        #
#    Updated: 2019/11/29 12:35:23 by abourbou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# for testing purpose
vpath %.c src
MAIN			=	ft_vect.c ft_vect2.c ray_tracing.c 
JOTRIQUE		=	gnl_to_shapes.c

# update this
vpath %.c src
SRC				=	ft_vect.c ft_vect2.c ft_vect3.c ray_tracing.c \
					cal_view.c  intersect_resolv.c surface_normal_vect.c \
					cal_color.c 

vpath %.o tmp
OBJ				=	$(SRC:.c=.o)

vpath %.h includes
INC 			=	./include/shapes.h \
					./include/ray_tracing.h \
					./include/intersect_resolv.h

NAME			=	miniRT.a

DEP_ARC			=	./libft/libft.a

TEST			=	./main_test/testRTglobal.c ./main_test/fct_de_test.c

CC				=	gcc

MINILBX 		= 	./minilibx_opengl_with_a/libmlx.a

CFLAGS			+=	-Wall -Wextra -Werror

LIBX			=	-I mlx -L ./minilibx_opengl \
				    -framework OpenGL -framework AppKit

RM				=	rm -f

all				:	$(NAME)

$(NAME)			:	$(OBJ) $(INC)
					$(MAKE) -C ./libft
					ar -rs $(NAME) $(OBJ)
# "$(MAKE) -C ./libft" works like "cd ./libft && Make && cd .."

%.o				:	%.c $(INC)
					$(CC) -c -o $@ $< $(CFLAGS)

debug			:
					echo $(NAME)

test            :
					$(CC) $(CFLAGS) $(LIBX) $(JOTRIQUE) $(DEP_ARC) && ./a.out
					make fclean
					rm a.out

unit_test		:	all
					$(CC) $(CFLAGS) -g -I $(INC) $(LIBX) $(MINILBX) $(DEP_ARC) $(TEST) $(NAME) && ./a.out
					make fclean
					#rm a.out

# add mains to valigrind & lldb (duh)

valgrind        :
					$(CC) -g3 $(CFLAGS) $(LIBX) $(DEP_ARC) && ./a.out
					valgrind ./a.out
					make fclean
					rm a.out
					rm -rf a.out.dSYM

lldb	        :
					$(CC) -g3 $(CFLAGS) $(LIBX) $(DEP_ARC) && ./a.out
					lldb a.out
					make fclean
					rm a.out
					rm -rf a.out.dSYM

del				:
					rm a.out
					rm -rf a.out.dSYM

clean			:
					$(RM) $(OBJ)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	clean fclean
