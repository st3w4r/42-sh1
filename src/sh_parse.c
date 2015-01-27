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

	array_argv = ft_strsplit(str_argv, ' ');
	return (array_argv);
}

char	**sh_parse_path(char *path)
{
	return (ft_strsplit(path, ':'));
}

void	sh_search_exec(char *array_path, char *cmd)
{
	int i;

	i = 0;
	while (array_path[i])
	{
		
	}
}
/*
char	*sh_get_env(char *env_find, char **env)
{
	int i;
	char **array;

	i = 0;
	while (env[i] != NULL)
	{
		array = ft_strsplit(env[i], '=');

		if (ft_strcmp(env_find, env[i]) == 0)
			return (env[1]);
		++i;
	}
	return (NULL);
}
*/
