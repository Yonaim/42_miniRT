LIB_PATH		= lib

CPPFLAGS		+= -I./$(LIB_PATH)/includes

# ************************************ MLX *********************************** #

LIBMLX			= libmlx.a

LIBMLX_PATH		= $(LIB_PATH)/libmlx
LIBMLX_FLAGS	= -framework OpenGL -framework AppKit
# LIBMLX_FLAGS	= -lXext -lX11 -lm -lz

LDFLAGS			+= -L./$(LIBMLX_PATH) $(LIBMLX_FLAGS)
LDLIBS			+= -lmlx

$(MLX):
	make -C $(LIBMLX_PATH)

# *********************************** LIBFT ********************************** #

LIBFT			= libft.a

LIBFT_PATH		= $(LIB_PATH)/libft

LDFLAGS			+= -L./$(LIBFT_PATH)
LDLIBS			+= -lft

$(LIBFT):
	make -C $(LIBFT_PATH)

# ********************************** LIBMATH ********************************* #

LIBMATH			= libmath.a

LIBMATH_PATH	= $(LIB_PATH)/libmath

CPPFLAGS		+= -I./$(LIB_PATH)/libmath/includes
LDFLAGS			+= -L./$(LIBMATH_PATH)
LDLIBS			+= -lmath

$(LIBMATH):
	make -C $(LIBMATH_PATH)
