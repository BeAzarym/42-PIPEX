/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:55:06 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/19 13:40:01 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	exec_cmd1(t_pipex *pipex, char **env, int fd[2])
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[1]);
		return (0);
	}
	close(fd[1]);
	pipex->fd[0] = open(pipex->infile, O_RDONLY);
	if (!pipex->fd[0])
		ft_error(pipex, ERR_OPEN_FAIL);
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		return (0);
	close(pipex->fd[0]);
	return (execve(pipex->cmd_1->cmd, pipex->cmd_1->args, env));
}

static int	exec_cmd2(t_pipex *pipex, char **env, int fd[2])
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		return (0);
	}
	close(fd[0]);
	pipex->fd[1] = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!pipex->fd[1])
		ft_error(pipex, ERR_OPEN_FAIL);
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		return (0);
	close(pipex->fd[1]);
	return (execve(pipex->cmd_2->cmd, pipex->cmd_2->args, env));
}

void	exec(t_pipex *pipex, char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error(pipex, ERR_PIPE_FAILED);
	pipex->pid[0] = fork();
	if (pipex->pid[0] == -1)
		ft_error(pipex, ERR_FORK_FAIL);
	if (pipex->pid[0] == 0)
		exec_cmd1(pipex, env, fd);
	pipex->pid[1] = fork();
	if (pipex->pid[1] == -1)
		ft_error(pipex, ERR_FORK_FAIL);
	if (pipex->pid[1] == 0)
		exec_cmd2(pipex, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pipex->pid[0], NULL, 0);
	waitpid(pipex->pid[1], NULL, 0);
}
