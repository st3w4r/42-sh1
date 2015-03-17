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

char ***g_env;

static void	sh_fork_procees(char *path, char **av, char **env)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		wait(0);
	else if (father == 0)
	{
		if (execve(path, av, env) == -1)
			ft_error_str(ft_strcat(av[0], " : exec format error.\n"));
		exit(0);
	}
}

int			sh_search_exec(char **array_path, char **argv, char **env)
{
	char *full_path;

	while (array_path && *array_path)
	{
		full_path = sh_read_dir(*array_path, argv[0]);
		if (full_path != NULL)
		{
			sh_fork_procees(full_path, argv, env);
			// FREE(full_path);
			return (1);
		}
		array_path++;
	}
	return (0);
}

int			sh_search_builtins(char **argv, char ***env)
{
	int		state;
	char	*path;
	char	**array_path;

	state = 0;
	if (ft_strcmp(argv[0], "cd") == 0)
		sh_builtin_cd(argv[1], env), state = 1;
	else if (ft_strcmp(argv[0], "env") == 0)
		sh_builtin_env(argv, *env), state = 1;
	else if (ft_strcmp(argv[0], "export") == 0 ||
			ft_strcmp(argv[0], "setenv") == 0)
		sh_builtin_setenv(argv, env), state = 1;
	else if (ft_strcmp(argv[0], "unsetenv") == 0)
		sh_builtin_unsetenv(argv, env), state = 1;
	else if (ft_strcmp(argv[0], "exit") == 0)
		sh_builtin_exit(argv), state = 1;
	else if (sh_grant_access(argv[0]) == 0)
		sh_fork_procees(argv[0], argv, *env), state = 1;
	else if (sh_exist_dir_file(argv[0]) == 1)
	{
		path = sh_get_env("PATH", *env);
		array_path = sh_parse_path(path);
		while (array_path && *array_path)
		{
			if (sh_read_dir(*array_path, argv[0]))
				return (0);
			++array_path;
		}
		sh_builtin_cd(argv[0], env), state = 1;
		// FREE(path);
		// FREE_ARR(array_path);
	}
	return (state);
}

static void		sh_exec_cmd(char *line, char **array_path, char ***new_env)
{
	char **argv;
	char **array_cmd;

	array_cmd = ft_strsplit(line, ';');
	while (*array_cmd)
	{
		while (*array_cmd[0] == ' ' || *array_cmd[0] == '\t')
			(*array_cmd)++;
		argv = sh_parse_argv(*array_cmd);
		if (argv[0] && sh_search_builtins(argv, new_env) == 0){
			if (sh_search_exec(array_path, argv, *new_env) == 0)
				ft_error_str(ft_strcat(argv[0], ": Command not found.\n"));}
		++array_cmd;
	}
	// FREE_ARR(array_cmd);
	// FREE_ARR(argv);
}

void			sh_loop(char **env)
{
	char *line;
	char *path;
	char **array_path;
	char **new_env;

	new_env = ft_arrcpy(env);
	g_env = &new_env;
	if (!(path = sh_get_env("PATH", new_env)))
		ft_error_str("Error PATH is NULL\n");
	while (42)
	{
		sh_display_prompt(new_env);
		if (ft_get_next_line(0, &line) == 0)
			sh_builtin_exit(0);
		path = sh_get_env("PATH", new_env);
		array_path = sh_parse_path(path);
		sh_exec_cmd(line, array_path, &new_env);
		// FREE(path);
		// FREE_ARR(array_path);
	}
}
