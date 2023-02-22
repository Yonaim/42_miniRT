
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!needle || *needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i + n_len) <= len)
	{
		if (ft_strncmp(&haystack[i], needle, n_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
