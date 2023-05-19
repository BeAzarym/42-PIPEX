/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:36:32 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/19 13:39:12 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static t_cmd	*init_cmd(void)
{
	t_cmd	*ptr;

	ptr = malloc(sizeof(t_cmd));
	if (!ptr)
		return (NULL);
	ptr->cmd = NULL;
	ptr->args = NULL;
	ptr->path = NULL;
	return (ptr);
}

t_pipex	*init_struct(t_pipex *ptr)
{
	ptr = malloc(sizeof(t_pipex));
	if (!ptr)
		ft_error(ptr, ERR_MALLOC_FAIL);
	ptr->paths = NULL;
	ptr->cmd_1 = init_cmd();
	if (!ptr->cmd_1)
		ft_error(ptr, ERR_MALLOC_FAIL);
	ptr->cmd_2 = init_cmd();
	if (!ptr->cmd_2)
		ft_error(ptr, ERR_MALLOC_FAIL);
	ptr->infile = NULL;
	ptr->outfile = NULL;
	ptr->fd[0] = -1;
	ptr->fd[1] = -1;
	ptr->pid[0] = -1;
	ptr->pid[1] = -1;
	return (ptr);
}
