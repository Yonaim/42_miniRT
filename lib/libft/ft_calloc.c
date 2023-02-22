
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*dst;

	dst = malloc(num * size);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, num * size);
	return (dst);
}
