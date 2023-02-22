
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n--)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
