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

static	void	sh_signal_sigint(int sig)
{
	ft_putendl("Signal");
	ft_putnbr(sig);
}

void	sh_signal_handler(int sig)
{
	if (sig == 2)
		sh_signal_sigint(sig);
	if (sig == 3)
		ft_putendl("QUIT");
}
