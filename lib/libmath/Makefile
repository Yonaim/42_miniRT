
.DEFAULT_GOAL := all
NAME = libmath.a

include config/definition.mk

# ******************************* basic rules ******************************** #

.PHONY : all bonus
all : $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

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
