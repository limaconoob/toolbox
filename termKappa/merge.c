/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 01:57:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/23 08:12:16 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termcap.h>
#include <termios.h>
#include <term.h>

/*
**	static int		c = 0;
**	else if (c < size[0] - 1 && way == 66)
**		c++;
**	else if (c > 0 && way == 65)
**		c--;
**	ft_putnbr(buf[0]);
**	ft_putchar(' ');
**	ft_putnbr(buf[1]);
**	ft_putchar(' ');
**	ft_putnbr(buf[2]);
**	ft_putchar('\n');
*/

static void			move_it(char *get, int way, int *size, int *i)
{
	char			*res;

	if (*i > 0 && way == 68)
		(*i)--;
	else if (*i < size[1] - 1 && way == 67)
		(*i)++;
	res = tgetstr("cm", &get);
	tputs(tgoto(res, *i, c), 1, outc);
}

static int			voir_touche(char *get)
{
	char			buf[3];
	static int		size[2];
	static int		w;
	static int		i = 0;

	size[0] = tgetnum ("li");
	size[1] = tgetnum ("co");
	while (1)
	{
		buf[0] = 0;
		buf[1] = 0;
		buf[2] = 0;
		read(0, buf, 3);
		if (!buf[1] && !buf[2])
		{
			if (buf[0] == 127 && i--)
				move_it(get, 127, size, &i);
			else
				i++;
			tputs(buf, 1, outc);
			if (buf[0] == 127)
				move_it(get, 127, size, &i);
		}
		else if (buf[0] == 27)
			move_it(get, buf[2], size, &i);
	}
	return (0);
}

char				*tgetall(void)
{
	char			*name_term;
	char			*term_buffer;
	struct termios	term;

	term_buffer = (char*)malloc(2048);
	name_term = getenv("TERM");
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	(void)tgetent(term_buffer, name_term);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	voir_touche(term_buffer);
}
