/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:33:56 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/19 15:23:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	clear_cmd_struct(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->cmd)
		ft_free(cmd->cmd);
	if (cmd->path)
		ft_free(cmd->path);
	if (cmd->args)
		ft_array_clear(cmd->args);
	ft_free(cmd);
}

void	ft_error(t_pipex *lst, char *error_code)
{
	ft_array_clear(lst->paths);
	clear_cmd_struct(lst->cmd_1);
	clear_cmd_struct(lst->cmd_2);
	ft_free(lst->infile);
	ft_free(lst->outfile);
	ft_free(lst);
	ft_putstr_fd("[Error]	", 2);
	ft_putstr_fd(error_code, 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_pipex *lst)
{
	ft_array_clear(lst->paths);
	clear_cmd_struct(lst->cmd_1);
	clear_cmd_struct(lst->cmd_2);
	ft_free(lst->infile);
	ft_free(lst->outfile);
	ft_free(lst);
	exit(EXIT_SUCCESS);
}
