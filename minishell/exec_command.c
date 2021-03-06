int	exec_cmd(char *cmd, char **env)
{
	char	*path;
	char	**cmd_params;

	path = find_path(cmd, &cmd_params, env);
	// if (path == NULL)
	// 	error_path_fd_2(process, av[4]);
	execve(path, cmd_params, env)
	printf("ERREUR execve");
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
	{
		return ;
	}
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strjoin_f(char *s 1, char const *s2)
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

char	**create_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char ***cmd_params,  char **env)
{
	char	*path;
	char	**paths;
	int		i;
	int		find;

	paths = create_paths(env);
	*cmd_params = ft_split(cmd, ' ');
	i = -1;
	find = 0;
	path = NULL;
	// if (*cmd_params[0] == NULL)
	// 	free_to_exit(paths, p);
	while (paths[++i] && !find)
	{
		free(path);
		paths[i] = ft_strjoin_f(paths[i], "/");
		path = ft_strjoin(paths[i], *cmd_params[0]);
		if (access(path, X_OK) == 0)
			find = 1;
	}
	free_tab(paths);
	if (find)
		return (path);
	free(path);
	return (check_absolute_path(*cmd_params[0]));
}

char	*check_absolute_path(char *path)
{
	if (access(path, F_OK) == 0)
		return (ft_strdup(path));
	else
		return (NULL);
}
