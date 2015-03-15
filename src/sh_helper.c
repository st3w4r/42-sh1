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
char	*sh_get_uid(void)
{

}
*/
char	*sh_get_hostname(void)
{
	char *buf;

	if (!(buf = malloc(255)))
		ft_malloc_error();
	*buf = 0;
	gethostname(buf, 255);
	return (buf);
}
char	*sh_replace_home(char *path, char **env)
{
	char *home_path;
	char *pos;

	home_path = sh_get_env("HOME", env);
	if ((pos = ft_strstr(path, home_path)))
	{
		path[0] = '~';
		path[1] = 0;
		ft_strcat(path, pos + ft_strlen(home_path));
	}
	if (home_path)
		free(home_path), home_path = NULL;
	return (path);
}

void	sh_display_prompt(char **env)
{
	char buf[1024];
	char *hostname;

	ft_putstr("\n");
	if ((hostname = sh_get_hostname()))
		ft_putstr(hostname), ft_putchar(' ');
	ft_putstr("\033[1;37m");
	if (getcwd(buf, 1024))
		ft_putendl(sh_replace_home(buf, env));
	ft_putstr("\033[0m");
	ft_putstr("$> ");
}

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
