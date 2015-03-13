/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:47:35 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/02 18:47:37 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
/*
t_uint	sh_tablen(char **tab)
{
	t_uint count;

	count = 0;
	while (tab && tab[count])
		++count;
	return (count);
}
*/
/*
char	**sh_copy_env(char **env)
{
	char **new_env;
	t_uint pos;

	if (!(new_env = (char**)malloc(sizeof(char *) * (sh_tablen(env) + 1))))
		ft_malloc_error();
	pos = 0;
	while (env && env[pos])
		new_env[pos] = ft_strdup(env[pos]), pos++;
	new_env[pos] = NULL;
	return (new_env);
}
*/
