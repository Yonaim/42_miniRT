LIB_PATH		= lib

# ************************************ MLX *********************************** #

LIBMLX			= libmlx.a

LIBMLX_PATH		= $(LIB_PATH)/libmlx
LIBMLX_FLAGS	= -framework OpenGL -framework AppKit
# LIBMLX_FLAGS	= -lXext -lX11 -lm -lz
$(MLX):
	make -C $(LIBMLX_PATH)

# *********************************** LIBFT ********************************** #

LIBFT			= libft.a

LIBFT_PATH		= $(LIB_PATH)/libft

$(LIBFT):
	make -C $(LIBFT_PATH)

# ********************************** LIBMATH ********************************* #

LIBMATH			= libmath.a

LIBMATH_PATH	= $(LIB_PATH)/libmath

$(LIBMATH):
	make -C $(LIBMATH_PATH)
