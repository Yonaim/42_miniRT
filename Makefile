.DEFAULT_GOAL	=	all

# program name
NAME			=	miniRT

# compile 
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP
CFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS		=	\
					-I./$(LIB_PATH)/libmath/includes \
					-I./$(LIB_PATH)/includes \
					-I./$(PART_PATH)/includes/structs \
					-I./$(PART_PATH)/includes
LDFLAGS			=	\
					-L./$(LIBFT_PATH) \
					-L./$(LIBMATH_PATH)
LDLIBS			=	-lft -lmath -lm

ifdef SANITIZE
CFLAGS			+=	$(CFLAGS_SANITIZE)
endif

# ********************************** LIBRARY ********************************* #

# libft, libmlx, libmath
include 			config/library.mk

# ********************************** miniRT ********************************* #

# determine part
ifdef BONUS
PART_PATH		=	bonus
PART_SUFFIX		=	_bonus
else
PART_PATH		=	mandatory
PART_SUFFIX 	=	
endif

# files
include				config/filename.mk

SRCS			=	$(addprefix ./$(PART_PATH)/srcs/, $(addsuffix $(PART_SUFFIX).c, $(FILENAME)))
OBJS			=	$(addprefix ./$(PART_PATH)/objs/, $(addsuffix $(PART_SUFFIX).o, $(FILENAME)))
DEPS			=	$(OBJS:.o=.d)

# build
include				config/build.mk

# ******************************* BASIC RULES ******************************** #

all:
	make get_filenames
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBMATH_PATH) --silent
	make $(NAME)

bonus:
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBMATH_PATH) --silent
	BONUS=1 make $(NAME)

clean:
	make -C $(LIBFT_PATH) clean --silent
	make -C $(LIBMATH_PATH) clean --silent
	$(RM) -rf mandatory/objs
	$(RM) -rf bonus/objs

fclean:
	make -C $(LIBFT_PATH) fclean --silent
	make -C $(LIBMATH_PATH) fclean --silent
	$(RM) -rf mandatory/objs
	$(RM) -rf bonus/objs
	$(RM) $(MINIRT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus

# ******************************* ASSIST RULES ******************************* #

ifdef DEBUG
LLDB	=	lldb
endif

library:
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBMATH_PATH) --silent

clean_test:
	rm ./test_parse_exe

build_parse: ./mandatory/srcs/parsing/*.c ./mandatory/srcs/object/*.c
	make library
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -g \
	./mandatory/srcs/parsing/*.c \
	./mandatory/srcs/object/*.c \
	-o ./test_parse_exe

test_parse:
	make build_parse
	$(LLDB) ./test_parse_exe ./sample.rt

get_filenames:
	sh dev/scripts/get_filenames.sh

image:
	sh dev/scripts/get_img_and_log.sh


.PHONY: library clean_test build_parse test_parse get_filenames image