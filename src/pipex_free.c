/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:19:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/02 02:48:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	if (cmd->size)
	{
		while (i < cmd->size)
		{
			free(cmd->cmd[i]);
			cmd->cmd[i] = NULL;
			i++;
		}
		free(cmd->cmd);
	}
	free(cmd->cmd_path);
	cmd->cmd_path = NULL;
	free(cmd);
	cmd = NULL;
}

void	free_pipex(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	free_command(pipex->cmd1);
	pipex->cmd1 = NULL;
	free_command(pipex->cmd2);
	pipex->cmd2 = NULL;
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		pipex->path[i] = NULL;
		i++;
	}
	free(pipex->path);
	pipex->path = NULL;
	free(pipex);
	pipex = NULL;
}

void	close_pipex(t_pipex *pipex)
{
	free_pipex(pipex);
	close (pipex->end[0]);
	close (pipex->end[1]);
}
