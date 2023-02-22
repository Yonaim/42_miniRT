
#include "utils_internal.h"

void	*fmt_memset(void *dst, int c, size_t nbytes)
{
	unsigned char	*ptr;

	if (dst == NULL)
		return (NULL);
	ptr = dst;
	while (nbytes--)
		*ptr++ = (unsigned char)c;
	return (dst);
}

void	*fmt_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_p;
	const char	*src_p;

	if (dst == 0 || src == 0)
		return (NULL);
	dst_p = dst;
	src_p = (const char *)src;
	while (n--)
		*dst_p++ = *src_p++;
	return (dst);
}
