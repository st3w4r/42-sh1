/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_setenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:01:56 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/04 16:02:01 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_sh1.h"

static char	*sh_builtin_setenv_new_val(char *name, char *value)
{
	char	*val_new;

	val_new = NULL;
	if (!(val_new = (char*)malloc((ft_strlen(name) + ft_strlen(value) + 2))))
		ft_malloc_error();
	*val_new = 0;
	val_new = ft_strcat(ft_strcat(ft_strcat(val_new, name), "="), value);
	return (val_new);
}

int			sh_builtin_setenv_add(char *name, char *value, char ***env)
{
	char	*val_new;
	char	**new_env;
	int		pos;

	if (!name || *name == '\0' || ft_strchr(name, '=') != NULL ||
		!value || !env)
		return (-1);

	pos = sh_get_env_pos(name, *env);
	val_new = sh_builtin_setenv_new_val(name, value);
	if (sh_get_env(name, *env))
		(*env)[pos] = val_new;
	else
	{
		if (!(new_env = (char**)malloc(sizeof(char *) * (ft_arrlen(*env) + 2))))
			ft_malloc_error();
		pos = 0;
		while (*env && (*env)[pos])
			new_env[pos] = (*env)[pos], pos++;
		new_env[pos] = val_new;
		new_env[++pos] = NULL;
		*env = new_env;
	}
	return (0);
}

int			sh_builtin_setenv(char **argv, char ***env)
{
	char **array_split;
	t_uint i;

	i = 0;
	if (!argv || !env)
		return (-1);
	while (argv[i] && !ft_strchr(argv[i], '='))
		++i;
	while (argv[i] && ft_strchr(argv[i], '='))
	{
		array_split = ft_strsplit(argv[i], '=');
		if (!array_split[1])
			array_split[1] = "";
		sh_builtin_setenv_add(array_split[0], array_split[1], env);
		++i;
	}
	return (0);
}
