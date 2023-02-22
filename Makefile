.DEFAULT_GOAL	= all

# program name
NAME			= miniRT

# compile 
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CFLAGS_SANITIZE	= -fsanitize=address
CPPFLAGS		= \
					-I./$(LIB_PATH)/includes \
					-I./$(LIB_PATH)/libmath/includes \
					-I./$(PART_PATH)/includes \
					-I./$(PART_PATH)/includes/structs
LDFLAGS			= \
					-L./$(LIBFT_PATH) \
					-L./$(LIBMLX_PATH) $(LIBMLX_FLAGS) \
					-L./$(LIBMATH_PATH)
LDLIBS			= -lft -lmlx -lmath

ifdef SANITIZE
CFLAGS		+=	CFLAGS_SANITIZE
endif

# ********************************** LIBRARY ********************************* #

# libft, libmlx, libmath
include 		config/library.mk

# ********************************** miniRT ********************************* #

# determine part
ifdef BONUS
PART_PATH		= bonus
PART_SUFFIX		= _bonus
else
PART_PATH		= mandatory
PART_SUFFIX 	= 
endif

# files
include			config/filename.mk
SRCS			= $(addprefix ./$(PART_PATH)/srcs/, $(addsuffix $(PART_SUFFIX).c, $(FILENAME)))
OBJS			= $(addprefix ./$(PART_PATH)/srcs/, $(addsuffix $(PART_SUFFIX).o, $(FILENAME)))

# build
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

# ******************************* BASIC RULES ******************************** #

all:
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBMLX_PATH) --silent
	make -C $(LIBMATH_PATH) --silent
	make $(NAME)

bonus:
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBMLX_PATH) --silent
	make -C $(LIBMATH_PATH) --silent
	BONUS=1 make $(NAME)

clean:
	make -C $(LIBFT_PATH) clean --silent
	make -C $(LIBMLX_PATH) clean --silent
	make -C $(LIBMATH_PATH) clean --silent
	$(RM) $(addprefix ./mandatory/srcs/, $(addsuffix .o, $(FILENAME)))
	$(RM) $(addprefix ./bonus/srcs/, $(addsuffix _bonus.o, $(FILENAME)))

fclean:
	make -C $(LIBMLX_PATH) clean --silent
	make -C $(LIBFT_PATH) fclean --silent
	make -C $(LIBMATH_PATH) fclean --silent
	$(RM) $(LIBMLX_PATH)/$(LIBMLX)
	$(RM) $(addprefix ./mandatory/srcs/, $(addsuffix .o, $(FILENAME)))
	$(RM) $(addprefix ./bonus/srcs/, $(addsuffix _bonus.o, $(FILENAME)))
	$(RM) $(MINIRT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
