/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:31:18 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/16 16:31:19 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include "../libft/includes/libft.h"
# include <unistd.h>

/*
** Name: sh_loop
** File: sh_loop.c
*/
void	sh_loop(char **env);

/*
** Name: sh_parce
** File: sh_parce.c
** Desc: All function about parsing
*/
char	**sh_parse_argv(char *str_argv);
char	**sh_parse_path(char *path);
// char	*sh_get_env(char *env_find, char **env);

#endif
