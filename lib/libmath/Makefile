
NAME = libmath.a
.DEFAULT_GOAL := all

include config/definition.mk

# ******************************* basic rules ******************************** #

.PHONY : all bonus
all : $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

bonus : all

include config/rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAG1) $(RMFLAG2) $(OBJ_PATH)

fclean : clean
	$(RM) $(RMFLAG1) $(NAME)

re :
	make fclean
	make all
