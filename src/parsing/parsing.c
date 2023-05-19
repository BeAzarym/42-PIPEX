/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:56:42 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/19 15:29:34 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static t_cmd	*parse_cmd(char **argv, t_pipex *lst, t_cmd *cmd)
{
	char	**tmp;

	tmp = ft_split(*argv, ' ');
	if (!tmp)
		ft_error(lst, ERR_MALLOC_FAIL);
	if (access(tmp[0], F_OK) > -1)
		cmd->cmd = ft_strdup(tmp[0]);
	else
		cmd->cmd = find_path(lst, tmp[0]);
	if (!cmd->cmd)
	{
		ft_array_clear(tmp);
		ft_error(lst, ERR_MALLOC_FAIL);
	}
	cmd->args = ft_strjoin_arr(cmd->cmd, &tmp[1], ft_arraylen(&tmp[1]));
	if (!cmd->args)
	{
		ft_array_clear(tmp);
		ft_error(lst, ERR_MALLOC_FAIL);
	}
	if (tmp)
		ft_array_clear(tmp);
	return (cmd);
}

char	*find_path(t_pipex *lst, char *cmd)
{
	int		i;
	char	*res;

	i = 0;
	while (lst->paths[i])
	{
		res = ft_strjoin(lst->paths[i], "/");
		if (!res)
			ft_error(lst, ERR_MALLOC_FAIL);
		res = ft_strjoin_s1(res, cmd);
		if (!res)
			ft_error(lst, ERR_MALLOC_FAIL);
		if (access(res, F_OK | X_OK) > -1)
			return (res);
		ft_free(res);
		i++;
	}
	return (ft_strdup(cmd));
}

void	get_path(char **env, t_pipex *lst)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			lst->paths = ft_split(&env[i][5], ':');
			if (!lst->paths)
				ft_error(lst, ERR_MALLOC_FAIL);
			return ;
		}
		i++;
	}
	return ;
}

void	parse_arg(char **argv, char **env, t_pipex *lst)
{
	get_path(env, lst);
	if (!lst->paths)
		ft_error(lst, ERR_PATH_ENV);
	lst->cmd_1 = parse_cmd(&argv[2], lst, lst->cmd_1);
	if (!lst->cmd_1)
		ft_error(lst, ERR_MALLOC_FAIL);
	lst->cmd_2 = parse_cmd(&argv[3], lst, lst->cmd_2);
	if (!lst->cmd_2)
		ft_error(lst, ERR_MALLOC_FAIL);
	lst->outfile = ft_strdup(argv[4]);
	if (!lst->outfile)
		ft_error(lst, ERR_MALLOC_FAIL);
	lst->fd[1] = open(lst->outfile, O_WRONLY | O_CREAT, 0644);
	if (lst->fd[1] < 0)
		ft_error(lst, ERR_OPEN_FAIL);
	close(lst->fd[1]);
	lst->infile = ft_strdup(argv[1]);
	if (!lst->infile)
		ft_error(lst, ERR_MALLOC_FAIL);
	if (access(lst->infile, F_OK | R_OK) == -1)
		ft_error(lst, ERR_INFILE);
	return ;
}
