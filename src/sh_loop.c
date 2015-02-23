/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 13:46:42 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/23 13:46:44 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void	sh_fork_procees(char *path, char **av, char **env)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	else if (father == 0)
		execve(path, av, env);
}

static void sh_search_exec(char **array_path, char **argv, char **env)
{
	char *full_path;

	while (*array_path)
	{
		full_path = sh_read_dir(*array_path, argv[0]);
		if (full_path != NULL)
			sh_fork_procees(full_path, argv, env);
		array_path++;
	}
}


void		sh_loop(char **env)
{
	char *line;
	char **argv;
	char *path;
	char **array_path;

	if (!(path = sh_get_env("PATH", env)))
		ft_error_str("Error PATH is NULL");
	// ft_putstr(path);
	while (42)
	{
		ft_putstr("$> ");
		ft_get_next_line(0, &line);
		array_path = sh_parse_path(path);
		argv = sh_parse_argv(line);
		sh_search_exec(array_path, argv, env);
	}
}
