/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:06:52 by amontant          #+#    #+#             */
/*   Updated: 2022/02/18 20:15:00 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd_1(char **av, char **env, int pipefd[2])
{
	char	*path;
	char	**cmd_params;
	int		infile_fd;

	path = find_path(av[2], env, &cmd_params);
	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd == -1 || path == NULL)
	{
		free_tab(cmd_params);
		free(path);
		error("ERROR BAD COMMAND OR BAD FILE\n");
	}
	dup2(infile_fd, 0);
	dup2(pipefd[1], 1);
	if (execve(path, cmd_params, env) == -1)
	{
		free_tab(cmd_params);
		free(path);
		error("ERROR EXECVE\n");
	}
}

void	exec_cmd_2(char **av, char **env, int pipefd[2])
{
	char	*path;
	char	**cmd_params;
	int		outfile_fd;

	path = find_path(av[3], env, &cmd_params);
	outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1 || path == NULL)
	{
		free_tab(cmd_params);
		free(path);
		error("ERROR BAD COMMAND OR BAD FILE\n");
	}
	dup2(outfile_fd, 1);
	dup2(pipefd[0], 0);
	if (execve(path, cmd_params, env) == -1)
	{
		free_tab(cmd_params);
		free(path);
		error("ERROR EXECVE\n");
	}
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
	{
		error("BAD ARGUMENTS\n");
		return (0);
	}
	if (pipe(pipefd) == -1)
		error("PROCESS CAN'T PIPE");
	pid = fork();
	wait(NULL);
	if (pid == -1)
		error("PROCESS CAN'T FORK");
	if (pid == 0)
	{
		close(pipefd[0]);
		exec_cmd_1(av, env, pipefd);
	}
	else
	{
		close(pipefd[1]);
		exec_cmd_2(av, env, pipefd);
	}
	return (0);
}
