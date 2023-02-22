# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 04:10:17 by yona              #+#    #+#              #
#    Updated: 2023/01/31 13:57:09 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I./includes
RM				= rm -f

# ****************************** GET_NEXT_LINE ******************************* #

GNL 			= libgnl.a
FILE 			=  \
					get_next_line
SRCS			= $(addsuffix $(SUFFIX).c, $(FILE))
OBJS			= $(SRCS:.c=.o)

$(GNL) : $(OBJS)
	ar crs $@ $^

# ******************************** MAKE RULES ******************************* #

all : $(GNL)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(GNL) $(OBJS)

re : 
	make fclean
	make all

.PHONY : all clean fclean re