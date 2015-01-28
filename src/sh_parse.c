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

// void	sh_search_exec(char *array_paths, char *cmd)
// {
// 	int i;
//
// 	i = 0;
// 	while (array_paths[i])
// 	{
//
// 	}
// }

char	*sh_get_env(char *env_find, char **env)
{
	char **array;
	char *ret;

	while (*env)
	{
		array = ft_strsplit(*env, '=');
		if (ft_strcmp(env_find, array[0]) == 0)
		{
			ret = ft_strdup(array[1]);
			ft_free_array(&array);
			return (ret);
		}
		env++;
	}
	ft_free_array(&array);
	return (NULL);
}