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
void	sh_loop(void);
char	**sh_parse_argv(char *str_argv);

#endif
