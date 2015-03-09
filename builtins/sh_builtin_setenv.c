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

static int	sh_builtin_get_env_pos(char *name, char **env)
{
	size_t	name_len;
	int		pos;

	pos = 0;
	name_len = ft_strlen(name);
	while (env[pos])
	{
		if (ft_strncmp(env[pos], name, name_len) == 0 &&
			(env[pos])[name_len] == '=')
			break ;
		++pos;
	}
	return (pos);
}

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

	pos = sh_builtin_get_env_pos(name, *env);
	val_new = sh_builtin_setenv_new_val(name, value);
	if (sh_get_env(name, *env))
		(*env)[pos] = val_new;
	else
	{
		if (!(new_env = (char**)malloc(sizeof(char *) * (sh_tablen(*env) + 2))))
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

int			sh_builtin_setenv(char *name, char *value, char ***env)
{
	if (!name || *name == '\0' || ft_strchr(name, '=') != NULL ||
		!value || !env)
		return (-1);
	return (sh_builtin_setenv_add(name, value, env));
}
