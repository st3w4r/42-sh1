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

/*
int		sh_get_env_pos(char *env_find, char **env)
{
	char	**array;
	char	*ret;

	// array = NULL;
	while (*env)
	{
		array = ft_strsplit(*env, '=');
		if (ft_strcmp(env_find, array[0]) == 0)
		{
			ret = ft_strdup(array[1]);
			return (ret);
		}
		++env;
	}
	return (0);
}
*/

int sh_builtin_setenv_add(char *name, char *value, char ***env)
{
	char *val_old;
	char *val_new;
	size_t val_len;
	size_t name_len;
	char **new_env;

	int pos;

	name_len = ft_strlen(name);
	val_len = ft_strlen(value);
	pos = 0;

	while ((*env)[pos])
	{
		if (ft_strncmp((*env)[pos], name, name_len) == 0 &&
			((*env)[pos])[name_len] == '=')
			break;
		pos++;
	}

	val_new = NULL;

	if (!(val_new = (char*)malloc((name_len + val_len + 2) * sizeof(char))))
		ft_malloc_error();
	// val_new = ft_strcat(val_new, name);
	// val_new = ft_strcat(ft_strcat(val_new, name), "=");
	val_new = ft_strcat(ft_strcat(ft_strcat(val_new, name), "="), value);
	//
	// ft_memcpy(val_new, name, name_len);
	// val_new[name_len] = '=';
	// ft_memcpy(&val_new[name_len + 1], value, val_len);
	// val_new[(name_len + val_len + 1)] = '\0';

	if ((val_old = sh_get_env(name, *env))) // Slot exist, replace content
	{
		free(val_old);
		(*env)[pos] = val_new;
	}
	else // Create new slot
	{
		if (!(new_env = (char**)malloc(sizeof(char *) * (sh_tablen(*env) + 2))))
			ft_malloc_error();
		pos = 0;
		while (*env && (*env)[pos])
		{
			new_env[pos] = (*env)[pos], pos++;
		}
		new_env[pos] = val_new;
		new_env[++pos] = NULL;
		*env = new_env;
	}

	return (0);
}

int sh_builtin_setenv(char *name, char *value, char ***env)
{
	if (!name || *name == '\0' || ft_strchr(name, '=') != NULL ||
		!value || !env)
		return (-1);
	return (sh_builtin_setenv_add(name, value, env));
}
