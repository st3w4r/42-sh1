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

char	*sh_get_uid(void)
{
	struct passwd *pwd;

	pwd = getpwuid(getuid());
	return (pwd == NULL ? NULL : pwd->pw_name);
}

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
	char *username;
	// char *result;
	//
	// *result = NULL;
	// if ()
	// ft_strcat()

	ft_putstr("\n");
	ft_putstr("\033[1;37m");
	if ((username = sh_get_uid()))
		ft_putstr(username);
	ft_putstr("\033[0m");
	ft_putchar('@');
	if ((hostname = sh_get_hostname()))
		ft_putstr(hostname);
	ft_putchar(' ');
	ft_putstr("\033[1;37m");
	if (getcwd(buf, 1024))
		ft_putendl(sh_replace_home(buf, env));
	ft_putstr("\033[0m");
	ft_putstr("$> ");
}
