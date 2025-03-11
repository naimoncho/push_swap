#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = ((unsigned char *) b);
	while (i < len)
	{
		s[i] = c;
		i ++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*copy;

	copy = malloc(nmemb * size);
	if (copy == NULL)
		return (NULL);
	ft_bzero(copy, nmemb * size);
	return (copy);
}
