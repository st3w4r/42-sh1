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

void	sh_builtin_cd(char *dir, char **env)
{
	if (dir == NULL)
		if (!(dir = sh_get_env("HOME", env)))
			return (ft_error_str("ft_minishell: cd: HOME not set\n"));

	if (ft_strcmp(dir, "-") == 0)
		if (!(dir = sh_get_env("OLDPWD", env)))
			return (ft_error_str("ft_minishell: cd: OLDPWD not set\n"));

	if (sh_exist_dir_file(dir) == 1)
	{
		if (chdir(dir) != 0)
			ft_error_str("Open erreur");
	}
	else
		ft_error_str("ft_minishell: cd: no such file or directory\n");
	free(dir);
}