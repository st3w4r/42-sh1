/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:31:18 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/07 14:17:28 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

typedef struct stat t_stat;
typedef struct dirent t_dirent;
typedef unsigned int t_uint;

struct s_lst
{
    char            *path;
    struct dirent   *rd;
    struct s_list   *next;
}   t_lst;

/*
** Name: sh_loop
** File: sh_loop.c
*/
void	sh_search_exec(char **array_path, char **argv, char **env);
void	sh_loop(char **environment);

/*
** Name: sh_parce
** File: sh_parce.c
** Desc: All function about parsing
*/
char	**sh_parse_argv(char *str_argv);
char	**sh_parse_path(char *path);
char	*sh_get_env(char *env_find, char **env);

/*
** Name: sh_files
** File: sh_files.c
** Desc: Open directory en search files
*/
t_uint	sh_grant_access(char *path_exec);
t_uint	sh_exist_dir_file(char *name);
char	*sh_read_dir(char *path, char *cmd);

/*
** Name: ft_error
** File: ft_error.c
** Desc: Gestion error
*/
void	ft_exit(void);
void	ft_malloc_error(void);
void	ft_error_str(char *str);
void	ft_error_str_exit(char *str);

/*
** Name: sh_builtin_cd
** File: sh_builtin_cd.c
** Desc: Builtin CD
*/
void	sh_builtin_cd(char *dir, char **env);
void	sh_builtin_env(char **argv, char **env);

/*
** Name: sh_builtin_setenv
** File: sh_builtin_setenv.c
** Desc: Builtin Setenv
*/
int		sh_builtin_setenv_add(char *name, char *value, char ***env);
int		sh_builtin_setenv(char **argv, char ***env);

/*
** Name: sh_builtin_exit
** File: sh_builtin_exit.c
** Desc: Builtin Exit with options
*/
void	sh_builtin_exit(char **argv);

/*
** Name: sh_helper
** File: sh_helper.c
** Desc: Functions Helper
*/
t_uint	sh_tablen(char **tab);
char	**sh_copy_env(char **env);

#endif
