#include "fillit.h"
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		return (*s1 - *s2);
	}
	return (0);
}

int	ft_length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_length(str));
}
