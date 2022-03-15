/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:03 by amontant          #+#    #+#             */
/*   Updated: 2022/03/15 18:04:50 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_path_fd(int fd, char *path, char **cmd_params, char *cmd)
{
	int	error_;

	error_ = 0;
	if (path == NULL)
		error_ = 1;
	if (path != cmd_params[0])
		free(path);
	free_tab(cmd_params);
	if (fd == -1)
		error(cmd);
	if (error_ == 1)
		error("error cmd1");
}

// void	check_fd(int fd, char *cmd, char **cmd_params)
// {
// 	if (path != cmd_params[0])
// 		free(path);
// 	free_tab(cmd_params);
// 	error("ERROR BAD COMMAND OR BAD FILE\n");
// }
