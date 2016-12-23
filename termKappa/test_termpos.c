/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:44:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/02 04:34:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termkappa.h"
#include "../libft.h"
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

static void		move_it2(char *get, int way)
{
	char		*res;
	static int	i = 0;
	static int	c = 0;

	if (i > 0 && way == 68)
		i--;
	else if (i < 79 && way == 67)
		i++;
	else if (c < 28 && way == 66)
		c++;
	else if (c > 0 && way == 65)
		c--;
	res = tgetstr("cm", &get);
	tputs(tgoto(res, i, c), 1, outc);
}

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

static int		cursor_pos(char *buf)
{
	int			tmp;
	int			i;

	tmp = 0;
	i = 2;
	write(1, "\e[6n", 5);
	read(1, buf, 9);
	while (buf[0] == 27 && buf[1] == 91 && ft_isdigit(buf[i]))
		tmp = (tmp * 10) + buf[i++] - '0';
	return (tmp);
}

int				main(void)
{
	int			ret;
	char		buf[9];
	char		*buf_term;

	char		*res;

	buf_term = the();
	res = tgetstr("cm", &buf_term);
	buf_clean(buf);
	ft_putnbr(cursor_pos(buf));
	buf_clean(buf);
	while ((ret = read(0, buf, 4))) {
		if (*buf == '\n')
		{
			ft_putchar('\n');
			ft_putnbr(cursor_pos(buf));
		}
		buf_clean(buf);
	}
	return (0);
}
