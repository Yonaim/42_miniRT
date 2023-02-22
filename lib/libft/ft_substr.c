
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
