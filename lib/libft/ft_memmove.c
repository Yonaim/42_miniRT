
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;

	if (!dst && !src)
		return (NULL);
	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	if (src_p >= dst_p)
	{
		while (len--)
			*dst_p++ = *src_p++;
	}
	else
	{
		while (len)
		{
			*(dst_p + len - 1) = *(src_p + len - 1);
			len--;
		}
	}
	return (dst);
}
