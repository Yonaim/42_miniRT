# ********************************** BUILD *********************************** #

# dependency rule
ifeq ($(MAKECMDGOALS), fclean)
else ifeq ($(MAKECMDGOALS), clean)
else
	-include $(DEPS)
endif


# build program
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

# compile object files
$(PART_PATH)/objs/camera/%.o : $(PART_PATH)/srcs/camera/%.c
	mkdir -p $(PART_PATH)/objs/camera
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/material/%.o : $(PART_PATH)/srcs/material/%.c
	mkdir -p $(PART_PATH)/objs/material
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/object/%.o : $(PART_PATH)/srcs/object/%.c
	mkdir -p $(PART_PATH)/objs/object
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/parsing/%.o : $(PART_PATH)/srcs/parsing/%.c
	mkdir -p $(PART_PATH)/objs/parsing
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/pdf/%.o : $(PART_PATH)/srcs/pdf/%.c
	mkdir -p $(PART_PATH)/objs/pdf
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/ray/%.o : $(PART_PATH)/srcs/ray/%.c
	mkdir -p $(PART_PATH)/objs/ray
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/shading/%.o : $(PART_PATH)/srcs/shading/%.c
	mkdir -p $(PART_PATH)/objs/shading
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/utils/%.o : $(PART_PATH)/srcs/utils/%.c
	mkdir -p $(PART_PATH)/objs/utils
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PART_PATH)/objs/%.o : $(PART_PATH)/srcs/%.c
	mkdir -p $(PART_PATH)/objs
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

