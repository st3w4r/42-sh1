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

static t_uint		sh_exist_dir_file(char *name)
{
	t_stat *file_stat;

	if (!(file_stat = (t_stat*)malloc(sizeof(t_stat))))
		ft_exit();
	if (lstat(name, file_stat) == -1)
		return (0);
	else if (S_ISDIR(file_stat->st_mode))
		return (1);
	else if (S_ISREG(file_stat->st_mode))
		return (2);
	return (0);
}

static t_uint		sh_grant_access(char *path_exec)
{
	if (sh_exist_dir_file(path_exec) == 2)
		if (access(path_exec, X_OK) == 0)
			return (0);
		else
			return (-1);
	else
		return (-1);
}


void	sh_read_dir(char *path, char *search_exec)
{
	DIR				*dir;
	struct dirent	*rd;
	char 			*full_path;
	t_uint			is_exec;
	/*t_lst			*list;
	t_lst 			n_elem;

	list = NULL;
	if (!(list = (t_lst*)malloc(sizeof(t_lst)))
		ft_malloc_error();*/

	if ((dir = opendir(path)) == NULL)
		ft_error_str("Error Open");
	while ((rd = readdir(dir)))
	{
		// ft_putstr(rd->d_name);
		// ft_putstr(" ");
		full_path = ft_strjoin(ft_strjoin(path, "/"), rd->d_name);
		// is_exec = 0;
		is_exec = sh_grant_access(full_path);
		if (is_exec == 0)
		{
			if (ft_strcmp(rd->d_name, search_exec) == 0)
			{
				ft_putstr("FIND");
			}
		}
	}
	if ((closedir(dir)) == -1)
		ft_error_str("Error Close");
}


// void sh_files()
// {
//
// }
