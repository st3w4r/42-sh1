/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:23:46 by ybarbier          #+#    #+#             */
/*   Updated: 2015/01/16 16:23:48 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	sh_loop(env);

	// nb_args = argc;
	return (0);
}
