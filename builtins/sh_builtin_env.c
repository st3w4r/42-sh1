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

static void	sh_builtin_env_usage(void)
{
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

t_uint		sh_args_len(char **argv)
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

static void	sh_builtin_env_exec(char **argv, char ***new_env, int i)
{
	char **array_path;
	char *val_env;

	while (argv[i] && ft_strchr(argv[i], '='))
		++i;
	if (argv[i])
	{
		val_env = sh_get_env("PATH", *new_env);
		array_path = sh_parse_path(val_env);
		if (argv[0] && sh_search_builtins(&(argv[i]), new_env) == 0)
			if (sh_search_exec(array_path, &(argv[i]), *new_env) == 0)
				ft_error_str("Command not found.\n");
		FREE(val_env);
		FREE_ARR(array_path);
	}
	else
		sh_print_env(*new_env);
}

void		sh_builtin_env(char **argv, char **env)
{
	int		i;
	t_uint	arg_len;
	char	**new_env;

	i = 1;
	new_env = NULL;
	if (!argv || !(*argv))
		return ;
	if (ft_strcmp(argv[1], "-h") == 0 || ft_strcmp(argv[1], "--help") == 0)
		return (sh_builtin_env_usage());
	if (ft_strcmp(argv[1], "-i") == 0)
	{
		i = 2;
		if (!(new_env = (char**)malloc(sizeof(char *) * (1))))
			ft_malloc_error();
		new_env[0] = NULL;
		arg_len = 0;
	}
	else
		new_env = ft_arrcpy(env);
	if (argv[i] || !ft_strchr(argv[i], '='))
		sh_builtin_setenv(&(argv[i]), &new_env);
	sh_builtin_env_exec(argv, &new_env, i);
	FREE_ARR(new_env);
}
