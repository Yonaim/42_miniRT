
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_d;
	const char	*ptr_s;

	if (dst == 0 && src == 0)
		return (NULL);
	ptr_d = dst;
	ptr_s = (const char *)src;
	while (n--)
		*ptr_d++ = *ptr_s++;
	return (dst);
}
