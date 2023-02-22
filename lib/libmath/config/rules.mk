
# **************************** dependency rules ****************************** #

ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEP)
endif

# ****************************** compile rules ******************************* #

# mandatory
$(VECTOR_OBJ_PATH)/%.o : $(VECTOR_SRC_PATH)/%.c
	@mkdir -p $(VECTOR_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(INC_FLAG) -o $@

$(OTHER_OBJ_PATH)/%.o : $(OTHER_SRC_PATH)/%.c
	@mkdir -p $(OTHER_OBJ_PATH)
	$(CC) -c $(CFLAGS) $< $(INC_FLAG) -o $@
