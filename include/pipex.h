/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:37:39 by cchabeau          #+#    #+#             */
/*   Updated: 2023/05/19 00:09:57 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_INVALID_ARGUMENT "The number of argument was wrong.\n"
# define ERR_FORK_FAIL "Forking failled.\n"
# define ERR_READ_FAIL "Reading failled.\n"
# define ERR_WRITE_FAIL "Writing failled.\n"
# define ERR_MALLOC_FAIL "Malloc failled.\n"
# define ERR_OPEN_FAIL "Openning failled.\n"
# define ERR_PATH_ENV "PATH environment variable not found.\n"
# define ERR_INFILE "Infile not found or not permetition.\n"
# define ERR_INVALID_CMD "Invalid command.\n"
# define ERR_DUP_FAILED "Dup2 failled.\n"
# define ERR_PIPE_FAILED "Pipe failled.\n"

# include "../src/libft/libft.h"
# include <sys/wait.h>

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*path;
}			t_cmd;

typedef struct s_pipex
{
	char	**paths;
	t_cmd	*cmd_1;
	t_cmd	*cmd_2;
	int		pid[2];
	int		fd[2];
	char	*infile;
	char	*outfile;
}			t_pipex;

void		ft_error(t_pipex *list, char *error_code);
void		ft_exit(t_pipex *lst);
t_pipex		*init_struct(t_pipex *ptr);
void		get_path(char **env, t_pipex *lst);
void		parse_arg(char **argv, char **env, t_pipex *lst);
char		*find_path(t_pipex *lst, char *cmd);
void		exec(t_pipex *pipex, char **env);
void		ft_free(void *ptr);

#endif