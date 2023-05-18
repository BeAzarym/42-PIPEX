/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:24:38 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/18 23:24:44 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **env)
{
	t_pipex *lst;

	lst = NULL;
	if (argc != 5)
		ft_error(lst, ERR_INVALID_ARGUMENT);
	lst = init_struct(lst);
	if (!lst)
		ft_error(lst, ERR_MALLOC_FAIL);
	parse_arg(argv, env, lst);
	exec(lst, env);
	ft_exit(lst);
	return (0);
}
