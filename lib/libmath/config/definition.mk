# **************************** command and flags ***************************** #

# compile
CC				=	cc
CFLAGS1			=	-MMD -MP
CFLAGS2			=	-Wall -Wextra -Werror
CFLAGS3			=	-fsanitize=address -g3
CFLAGS			=	$(CFLAGS1) $(CFLAGS2)

ifdef FSANITIZE_FLAG
	CFLAGS		+=	$(CFLAGS3)
endif

# library archive
AR				=	ar
ARFLAGS			=	crs

# remove
RM				=	rm
RMFLAG1			=	-f
RMFLAG2			=	-r


# ********************************* library ********************************** #

# library flag
LIBFLAGS		=	-lm

# ******************************** directory ********************************* #

SRC_DIR			=	srcs
OBJ_DIR			=	objs
INC_DIR			=	includes

VECTOR_DIR		=	vector3

# ******************************* header files ******************************* #

# directory path
INC_PATH		=	$(INC_DIR)

# flags
INC_FLAG		=	-I./$(INC_PATH)

# ******************************* object files ******************************* #

# directory path
OBJ_PATH		=	$(OBJ_DIR)
SRC_PATH		=	$(SRC_DIR)

VECTOR_SRC_PATH =	$(SRC_PATH)/$(VECTOR_DIR)
OTHER_SRC_PATH	=	$(SRC_PATH)

VECTOR_OBJ_PATH	=	$(OBJ_PATH)/$(VECTOR_DIR)
OTHER_OBJ_PATH	=	$(OBJ_PATH)

VECTOR_FILE		=	v3_basic \
					v3_create \
					v3_length \
					v3_normalize \
					v3_product \
					v3_random
OTHER_FILE		=	angle \
					clamp \
					quadratic \
					random

# file name(absolute path)
VECTOR_OBJ		=	$(addprefix $(VECTOR_OBJ_PATH)/, $(addsuffix .o, $(VECTOR_FILE)))
OTHER_OBJ		=	$(addprefix $(OTHER_OBJ_PATH)/, $(addsuffix .o, $(OTHER_FILE)))
OBJ				=	$(VECTOR_OBJ) $(OTHER_OBJ)

# ****************************** dependency files ***************************** #

DEP				=	$(OBJ:.o=.d)
