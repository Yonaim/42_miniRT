.DEFAULT_GOAL	=	all

# program name
NAME			=	miniRT

# compile 
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -MP
CFLAGS_SANITIZE	=	-fsanitize=address -g3
CPPFLAGS		=	\
					-I./$(LIB_PATH)/includes \
					-I./$(LIB_PATH)/libmath/includes \
					-I./$(PART_PATH)/includes \
					-I./$(PART_PATH)/includes/structs
LDFLAGS			=	\
					-L./$(LIBFT_PATH) \
					-L./$(LIBMLX_PATH) $(LIBMLX_FLAGS) \
					-L./$(LIBMATH_PATH)
LDLIBS			=	-lft -lmlx -lmath -lm

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
# dependency rule
ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEPS)
endif

# build program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS) $(LDFLAGS)

$(PART_PATH)/objs/%.o : $(PART_PATH)/srcs/%.c
	mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# ******************************* BASIC RULES ******************************** #

all:
	make get_filenames
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

# ******************************* ASSIST RULES ******************************* #

ifdef DEBUG
LLDB	=	lldb
endif

library:
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBMLX_PATH) --silent
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

.PHONY: library clean_test build_parse test_parse get_filenames
