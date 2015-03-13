/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 11:13:35 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/02 11:13:39 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_sh1.h"

static void	sh_builtin_env_usage(void) {
	ft_error_str("usage: env [-i] [name=value ...] [utility [argument ...]]\n");
}

static void sh_print_env(char **env)
{
	while (env && *env)
	{
		ft_putendl(*env);
		++env;
	}
}

t_uint	sh_args_len(char **argv)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '='))
			count++;
		++i;
	}
	return (count);
}

void	sh_builtin_env(char **argv, char **env)
{
	int i;
	t_uint count;
	t_uint arg_len;
	char **new_env;
	char **array_path;
	// char **array_split;

	i = 0;
	new_env = NULL;

	if (!argv || !(*argv))
		return ;
	if (ft_strcmp(argv[1], "-h") == 0 || ft_strcmp(argv[1], "--help") == 0)
		return (sh_builtin_env_usage());
	if (ft_strcmp(argv[1], "-i") == 0)
	{
		i = 2;
		arg_len = ft_arrlen(argv);
		if (!(new_env = (char**)malloc(sizeof(char *) * arg_len + 1)))
			ft_malloc_error();
		arg_len = 0;
	}
	else
	{
		i = 1;

		// array_split = ft_strsplit(argv[i], );
		// sh_builtin_setenv(argv[i]);


		arg_len = ft_arrlen(env) + sh_args_len(argv);
		if (!(new_env = (char**)malloc(sizeof(char *) * arg_len + 1)))
			ft_malloc_error();
		count = 0;
		while (env && env[count])
			new_env[count] = env[count], count++;
		arg_len -= sh_args_len(argv);
	}

	if (argv[i] || !ft_strchr(argv[i], '='))
		sh_builtin_setenv(&(argv[i]), &new_env);

	/*
	while (argv[i] && ft_strchr(argv[i], '='))
	{
		array_split = ft_strsplit(argv[i], '=');
		if (!array_split[1])
			array_split[1] = "";
		sh_builtin_setenv(array_split[0], array_split[1], &new_env);
		++i;
		// new_env[arg_len++] = ft_strdup(argv[i]), ++i;
	}
	*/
	//
	// sh_builtin_setenv("SHELL", "What", &new_env);
	// sh_builtin_setenv("OK", "Test", &new_env);
	// sh_builtin_setenv("OKLoLWhat", "TestOOOOOOA", &new_env);
	// sh_builtin_setenv("s", "Test", &new_env);
	// sh_builtin_setenv("YOUPI", "TesaAaaas", &new_env);

///Execution command

	while (argv[i] && ft_strchr(argv[i], '='))
		++i;
	if (argv[i])
	{
		array_path = sh_parse_path(sh_get_env("PATH", new_env));

		if (argv[0] && sh_search_builtins(&(argv[i]), &new_env) == 0)
			if (sh_search_exec(array_path, &(argv[i]), new_env) == 0)
				ft_error_str(ft_strcat(argv[0], ": Command not found.\n"));
	}
	else
		sh_print_env(new_env);
}
