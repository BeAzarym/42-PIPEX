/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:33:56 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/16 17:14:17 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void clear_cmd_struct(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free(cmd->cmd);
	free(cmd->path);
	ft_array_clear(cmd->args);
	free(cmd);
}

void	ft_error(t_pipex *lst, char *error_code)
{
	ft_array_clear(lst->paths);
	clear_cmd_struct(lst->cmd_1);
	clear_cmd_struct(lst->cmd_2);
	free(lst->infile);
	free(lst->outfile);
	free(lst);
	ft_putstr_fd("[Error]	", 2);
	ft_putstr_fd(error_code, 2);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_pipex *lst)
{
	ft_array_clear(lst->paths);
	clear_cmd_struct(lst->cmd_1);
	clear_cmd_struct(lst->cmd_2);
	free(lst->infile);
	free(lst->outfile);
	free(lst);
	exit(EXIT_SUCCESS);
}
