/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:25:27 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/26 14:25:29 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**sh_parse_argv(char *str_argv)
{
	char **array_argv;

	array_argv = ft_strsplit(str_argv, ' ');
	return array_argv;
}
