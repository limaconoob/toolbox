/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:44:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/04 23:53:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termkappa.h"
#include "../libft.h"
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

static void		buf_clean(char *buf)
{
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = 0;
	buf[4] = 0;
	buf[5] = 0;
	buf[6] = 0;
	buf[7] = 0;
	buf[8] = 0;
}

int				main(void)
{
	int			ret;
	char		buf[9];
	char		*buf_term;

	buf_term = the();
	buf_clean(buf);
	ft_putstr("bonjour");
	while ((ret = read(0, buf, 8))) {
		if (*buf == 'N')
			return (0);
		if (buf[2] == 67 || buf[2] == 68)
			ft_putstr(buf);
		else
		{
			ft_putstr("\033[");
			ft_putnbr(31);
			ft_putchar(';');
			ft_putnbr(47);
			ft_putchar(';');
			ft_putnbr(4);
			ft_putchar('m');
			ft_putchar(*buf);
		}
		buf_clean(buf);
	}
	return (0);
}
