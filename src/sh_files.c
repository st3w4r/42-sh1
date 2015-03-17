/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:53:04 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/28 15:53:06 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

inline t_uint	sh_exist_dir_file(char *name)
{
	int		state;
	t_stat	*file_stat;

	state = 0;
	if (!(file_stat = (t_stat*)malloc(sizeof(t_stat))))
		ft_exit();
	if (lstat(name, file_stat) == -1)
		state = 0;
	else if (S_ISDIR(file_stat->st_mode))
		state = 1;
	else if (S_ISREG(file_stat->st_mode))
		state = 2;
	FREE(file_stat);
	return (state);
}

inline t_uint	sh_grant_access(char *path_exec)
{
	if (sh_exist_dir_file(path_exec) == 2)
		if (access(path_exec, X_OK) == 0)
			return (0);
		else
			return (-1);
	else
		return (-1);
}

static char			*sh_search_exec_cmd(char *path, char *file_name, char *cmd)
{
	char	*full_path;
	char	*path_replace;
	t_uint	is_exec;

	path_replace = ft_strjoin(path, "/");
	full_path = ft_strjoin(path_replace, file_name);
	FREE(path_replace);
	is_exec = -1;
	is_exec = sh_grant_access(full_path);
	if (is_exec == 0)
		if (ft_strcmp(file_name, cmd) == 0)
			return (full_path);
	FREE(full_path);
	return (NULL);
}

char				*sh_read_dir(char *path, char *cmd)
{
	DIR				*dir;
	struct dirent	*rd;
	char			*full_path;

	if ((dir = opendir(path)) == NULL)
		return (NULL);
	while ((rd = readdir(dir)))
	{
		full_path = sh_search_exec_cmd(path, rd->d_name, cmd);
		if (full_path != NULL)
			return (full_path);
	}
	if ((closedir(dir)) == -1)
		return (NULL);
	return (NULL);
}


// void sh_files()
// {
//
// }
