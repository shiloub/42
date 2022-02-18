#include "pipex.h"

char	**create_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while(ft_strncmp(env[i], "PATH=", 5))
		i++;
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
char	*ft_strjoin_f(char *s1, char const *s2)
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
	free(s1);
	return (strcat);
}
char	*find_path(char *cmd, char **env, char ***cmd_params)
{
	char	*path;
	char	**paths;
	int		i;
	int		find;

	paths = create_paths(env);
	*cmd_params = ft_split(cmd, ' ');
	i = 0;
	find = 0;
	path = NULL;
	while(paths[i] && !find)
	{
		free(path);
		paths[i] = ft_strjoin_f(paths[i], "/");
		path = ft_strjoin(paths[i], *cmd_params[0]);
		if (access(path, F_OK) == 0)
			find = 1;
		i++;
	}
	free_tab(paths);
	if (find)
		return(path);
	free(path);
	return(NULL);
}


