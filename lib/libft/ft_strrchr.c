
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*occur;

	if ((char) c == '\0')
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	occur = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
			occur = ((char *)&s[i]);
		i++;
	}
	return (occur);
}
