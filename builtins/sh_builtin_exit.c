/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 22:07:44 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/10 22:07:46 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_sh1.h"

void	sh_builtin_exit(char **argv)
{
	unsigned char exit_val;

	exit_val = 0;
	if (argv && argv[1])
	{
		if (ft_isdigit(argv[1][0]))
			exit_val = ft_atoi(argv[1]);
		else
		{
			ft_putendl("exit: Expression Syntax.");
			return ;
		}
	}
	ft_putendl("exit");
	exit(exit_val);
}
