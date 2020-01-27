# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/11/14 10:41:55 by abourbou     #+#   ##    ##    #+#        #
#    Updated: 2020/01/27 10:14:15 by abourbou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# Makes everything silent
#MAKEFLAGS		+=	--silent

.PHONY			:	all clean fclean re libft mlx

NAME			=	miniRT

#* OS differences

# UNAME			:=	$(shell uname)

# ifeq ($(UNAME), Darwin)
# framework		=	-framework
# OGL				=	OpenGl
# APPK			=	AppKit
# FLAG_OS			=	$(FRAME) $(APPK) $(FRAME) $(OGL)
# MLX_PATH		=	mlx_macos
# endif
# ifeq ($(UNAME), Linux)
# FLAG_X11		=	-lXext -lX11
# FLAG_THREAD		=	-lpthread
# FLAG_MATH		=	-lm
# FLAG_OS			=	$(FLAG_THREAD) $(FLAG_X11) $(FLAG_MATH)
# MLX_PATH		=	mlx_x11
# endif

#* Common tools

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f
OPTI_FLAG		=	-O2

#* Testing tools

PED				=	-pedantic
ASAN			=	-fsanitize=address -g3
VALTAG			=	--leak-check=full --show-leak-kinds=all
VALTRACK		=	--track-origins=yes -s

#* Dependencies

LIBFT_PATH		=	libft
LIBFT_INC		=	$(LIBFT_PATH)
LIBFT_A			=	$(LIBFT_PATH)/libft.a

#? local ici ou os dependant plus haut
MLX_PATH		=	libx/minilibx_opengl
MLX_INC			=	$(MLX_PATH)
MLX_A			=	$(MLX_PATH)/libmlx.a
MLX_COMP		=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

#* Sources

SRC				=	src/parsing/atod.c \
					src/parsing/char_operations.c \
					src/parsing/get_needed_param.c \
					src/parsing/get_param.c \
					src/parsing/get_shape_param.c \
					src/parsing/get_vect.c \
					src/parsing/int_operations.c \
					src/parsing/list_add_back.c \
					src/parsing/list_clear.c \
					src/parsing/list_operations.c \
					src/parsing/parsing.c \
					src/parsing/rgb_to_int.c \
					src/parsing/shape_type.c \
					src/parsing/skip.c \
					src/parsing/norme_all.c \
					src/parsing/parse_error_handling.c \
					src/parsing/parse_error_handling2.c \
					src/ray_tracing/cal_color.c \
					src/ray_tracing/cal_coord.c \
					src/ray_tracing/ft_vect.c \
					src/ray_tracing/ft_vect2.c \
					src/ray_tracing/ft_vect3.c \
					src/ray_tracing/intersect_resolv.c \
					src/ray_tracing/ray_tracing.c \
					src/ray_tracing/surface_normal_vect.c \
					src/ray_tracing/is_null.c \
					src/ray_tracing/intersect_resolv2.c \
					src/ray_tracing/intersect_cyl.c \
					src/ray_tracing/open_window.c \
					src/ray_tracing/open_window2.c \
					src/print_image.c

INC_PATH		=	includes
INC_NAME		=	shapes.h \
					parsing.h \
					raytracing.h \
					intersect_resolv.h \
					print_image.h

INCLUDES		=	-I$(LIBFT_INC) -I$(MLX_PATH) -I$(INC_PATH)

OBJ				=	$(SRC:.c=.o)

INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))

all				:	$(NAME)

$(NAME)			:	libft mlx $(OBJ) $(INC)
					$(CC) $(CFLAGS) $(INCLUDES) $(MLX_COMP) $(LIBFT_A) $(OBJ) src/main.c -o $(NAME)

common			:	$(NAME)
					./miniRT src/misc/3planes_3lights.rt

sanitize		:	libft mlx $(OBJ)
					$(CC) $(CFLAGS) $(ASAN) $(INCLUDES) $(MLX_COMP) $(LIBFT_A) $(OBJ) src/main.c -o $(NAME)

save			:	all
					./miniRT src/misc/lost_in_space.rt --save

clean_shot		:
					$(RM) image**.bmp

norme			:
					norminette src/parsing src/*.c src/ray_tracing includes libft

libft			:	$(LIBFT_A)
$(LIBFT_A)		:
					@ make -C $(LIBFT_PATH)

mlx				:	$(MLX_A)
$(MLX_A)		:
					@ make -C $(MLX_PATH)

%.o				:	%.c $(INC)
					$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

#* Much needed tidying up

clean			:
					$(RM) $(OBJ)
					$(RM) $(INC_PATH)/*.gch
					$(RM) image**.bmp

fclean			:	clean
					$(RM) $(NAME)
					@ make -C $(LIBFT_PATH) fclean
					@ make -C $(MLX_PATH) clean

re				:	fclean all