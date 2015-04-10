/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:19:03 by ybarbier          #+#    #+#             */
/*   Updated: 2015/02/23 18:23:41 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_sh1.h"

static void	sh_builtin_cd_open(char *dir, char ***env)
{
	char buf[1024];

	if (getcwd(buf, 1024))
		sh_builtin_setenv_add("OLDPWD", buf, env);
	if (chdir(dir) != 0)
		ft_error_str("Open erreur");
	if (getcwd(buf, 1024))
		sh_builtin_setenv_add("PWD", buf, env);
}

int			sh_builtin_cd_auto(char ***env, char *dir)
{
	char	*path;
	char	**array_path;
	int		pos;

	pos = 0;
	path = sh_get_env("PATH", *env);
	array_path = sh_parse_path(path);
	while (array_path && array_path[pos])
	{
		if (sh_read_dir(array_path[pos], dir))
		{
			FREE(path);
			FREE_ARR(array_path);
			return (0);
		}
		++pos;
	}
	sh_builtin_cd(dir, env);
	FREE(path);
	FREE_ARR(array_path);
	return (1);
}

void		sh_builtin_cd(char *dir, char ***env)
{
	char *val;

	val = ft_strdup(dir);
	if (val == NULL)
	{
		if (!(val = sh_get_env("HOME", *env)))
			return (ft_error_str("ft_minishell: cd: HOME not set\n"));
	}
	else if (ft_strcmp(val, "-") == 0)
	{
		FREE(val);
		if (!(val = sh_get_env("OLDPWD", *env)))
			return (ft_error_str("ft_minishell: cd: OLDPWD not set\n"));
	}
	else if (ft_strcmp(val, "~") == 0)
	{
		FREE(val);
		if (!(val = sh_get_env("HOME", *env)))
			return (ft_error_str("ft_minishell: cd: HOME not set\n"));
	}
	if (sh_exist_dir_file(val) == 1)
		sh_builtin_cd_open(val, env);
	else
		ft_error_str("ft_minishell: cd: no such file or directory\n");
	FREE(val);
}
