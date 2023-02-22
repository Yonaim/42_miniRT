
#ifndef UTILS_H
# define UTILS_H

/*--------------- STANDARD HEADERS ----------------*/

# include <stddef.h>

/*-------------- FUNCTION PROTOTYPES -------------*/

int		ft_max(int a, int b);
int		ft_min(int a, int b);

size_t	fmt_strlen(const char *str);
int		fmt_strchr(const char *str, char c);
void	fmt_str_toupper(char *str, size_t len);
char	*fmt_strdup(const char *s1);

void	*fmt_memcpy(void *dst, const void *src, size_t n);
void	*fmt_memset(void *dst, int c, size_t nbytes);

int		fmt_atoi(const char **str);

#endif
