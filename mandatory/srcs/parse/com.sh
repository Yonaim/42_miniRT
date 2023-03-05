CFLAGS="-Wall -Werror -Wextra"
SRCS="tokenize.c tokenize_utils.c is_word_token_str.c get_identifier_type.c ../dynamic_array/*.c"
# SRCS="ft_atof.c"
LIBRARY="-L../../../lib/libft -lft"
INCLUDE="-I../../includes -I../../../lib/includes -I../../../lib/libmath/includes -I../../includes/structs"
cc $CFLAGS $SRCS $LIBRARY $INCLUDE
./a.out
rm a.out