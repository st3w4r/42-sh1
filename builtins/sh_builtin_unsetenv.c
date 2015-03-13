/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:34:41 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/11 18:34:44 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_sh1.h"

static int	sh_builtin_unsetenv_remove(char *name, char ***env)
{
	int pos;
	char **p;

	if (!name || *name == '\0' || !env)
		return (-1);
	pos = sh_get_env_pos(name, *env);
	free((*env)[pos]);
	p = &((*env)[pos]);
	while (*p)
	{
		if (!(p[0] = p[1]))
			break;
		p++;
	}
	return (0);
}

int			sh_builtin_unsetenv(char **argv, char ***env)
{
	char *val_env;

	if (!argv || !env || !argv[1])
		return (-1);
	val_env = sh_get_env(argv[1], *env);
	if (!val_env)
		return (-1);
	return (sh_builtin_unsetenv_remove(argv[1], env));
}
