
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	srcsize;
	int		i;

	srcsize = 0;
	while (s1[srcsize])
		srcsize++;
	dst = malloc(srcsize + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	dst[i] = '\0';
	return (dst);
}
