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

void sh_search_exec(char **array_path, char **argv, char **env)
{
	char *full_path;

	while (array_path && *array_path)
	{
		full_path = sh_read_dir(*array_path, argv[0]);
		if (full_path != NULL)
			sh_fork_procees(full_path, argv, env);
		array_path++;
	}
}

static int sh_search_builtins(char **argv, char **env)
{
	/*
	if (ft_strcmp(argv[0], "cd") == 0)
		sh_builtin_cd(argv[1], env);
	else if (ft_strcmp(argv[0], "env") == 0)
		sh_builtin_env(argv)*/

	if (ft_strcmp(argv[0], "cd") == 0)
	{
		sh_builtin_cd(argv[1], env);
		return (1);
	}
	else if (ft_strcmp(argv[0], "env") == 0)
	{
		sh_builtin_env(argv, env);
		return (1);
	}
	return (0);
}

void		sh_loop(char **environment)
{
	char *line;
	char **argv;
	char *path;
	char **array_path;
	char **env;

	env = environment;
	if (!(path = sh_get_env("PATH", env)))
		ft_error_str("Error PATH is NULL\n");
	while (42)
	{
		ft_putstr("$> ");
		ft_get_next_line(0, &line);
		array_path = sh_parse_path(path);
		argv = sh_parse_argv(line);
		if (argv[0] && sh_search_builtins(argv, env) == 0)
		{

			// sh_search_exec(array_path, argv, env);
		}
	}
}
