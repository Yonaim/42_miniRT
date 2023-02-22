
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*------------------ HEADERS ---------------------*/

# include <unistd.h>
# include <stdlib.h>

/* ----------- DEFINE MACRO CONSTANTS ------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# define FAIL -1
# define SUCCESS 0

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_buff
{
	char	str[BUFFER_SIZE];
	int		lf_idx;
	int		offset;
	int		rbytes;
}	t_buff;

typedef struct s_line
{
	char	*str;
	int		len;
}	t_line;

/*-------------- FUNCTION PROTOTYPES -------------*/

int		get_next_lf_idx(t_buff *buf);
char	*append_buf_to_line(t_line *line, t_buff *buf, int start, int end);
char	*final_append_and_complete_line(t_line *line, t_buff *buf, \
int start, int end);
int		do_read_next(int fd, t_buff *buf, t_line *line);

#endif