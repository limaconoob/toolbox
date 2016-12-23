/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 08:21:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/25 17:04:14 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <termcap.h>
#include <termios.h>
#include <term.h>

void			move_it(int way, int *size, t_coord *get)
{
	char		*res;

	if (size[0] > 10 && way == 68)
		(size[0])--;
	else if (size[0] < params->term_x && way == 67)
		(size[0])++;
	else if (size[0] == params->term_x && way == 67)
	{
		size[0] = 0;
		size[2]++;
	}
	res = tgetstr("cm", &(params->get_term));
	tputs(tgoto(res, size[0], size[1]), 1, outc);
}
