# ******************************** DEBUG RULES ******************************* #


.PHONY: library clean_test build_parse test_parse get_filenames
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
