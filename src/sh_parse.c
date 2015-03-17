/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:25:27 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/26 14:25:29 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**sh_parse_argv(char *str_argv)
{
	char **array_argv;

	str_argv = ft_strreplace_char(str_argv, '\t', ' ');
	array_argv = ft_strsplit(str_argv, ' ');
	return (array_argv);
}

char	**sh_parse_path(char *path)
{
	return (ft_strsplit(path, ':'));
}

char	*sh_get_env(char *env_find, char **env)
{
	char	**array;
	char	*ret;

	array = NULL;
	while (*env)
	{
		array = ft_strsplit(*env, '=');
		if (ft_strcmp(env_find, array[0]) == 0)
		{
			ret = ft_strdup(array[1]);
			FREE_ARR(array);
			return (ret);
		}
		FREE_ARR(array);
		++env;
	}
	return (NULL);
}

int		sh_get_env_pos(char *name, char **env)
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
