
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}
