LIB_PATH		= lib

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
