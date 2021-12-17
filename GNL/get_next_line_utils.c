#include <stdio.h>
#include <stdlib.h>
int ft_strchr(char *str, char c)
{
    int i;
    i = 0;

    while(str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return 0;
}int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	char	*strcat;
	int		i;

	lens1 = ft_strlen((char *)s1);
	i = 0;
	strcat = malloc(sizeof(char) * (lens1 + ft_strlen((char *)s2) + 1));
	if (!strcat)
		return (0);
	while (s1[i])
	{
		strcat[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		strcat[i + lens1] = s2[i];
		i++;
	}
	strcat[i + lens1] = '\0';
	return (strcat);
}
