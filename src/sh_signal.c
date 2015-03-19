/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 20:31:31 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/13 20:31:33 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static	void	sh_signal_sigint(void)
{
	ft_putstr("\n");
	if (g_env && *g_env)
		sh_display_prompt(*g_env);
}

static void		sh_signal_handler(int sig)
{
	if (sig == SIGINT)
		sh_signal_sigint();
}

void			sh_signal_gestion(void)
{
	signal(SIGINT, sh_signal_handler);
}
