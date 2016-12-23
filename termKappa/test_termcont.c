/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:44:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/12/17 08:54:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termkappa.h"
#include "../libft.h"
#include <stdio.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>

int				main(void)
{
	int			ret;
	char		buf[14];
	char		*buf_term;

	buf_term = the();
	ft_bzero(buf, 14);
	ft_putstr("\x1B(B\x1b[4l\x1b[?7h\x1B[?1h\x1b=\x1b[?1000h\x1b[?1h\x1B>");
//	ft_putstr("\x1b[?1000h\x1b[?1002h\x1b[?1015h\x1b[?1006h");
//  ft_putstr("\x1b[c");
	while ((ret = read(1, buf, 14))) {
		if (*buf == 'q')
			return (0);
		printf("%d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10], buf[11], buf[12], buf[13]);
		printf("%c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10], buf[11], buf[12], buf[13]);
//		printf("%c %c %c %c %c %c %c %c %c %c %c %c %c\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8]/*, buf[9]*/, buf[10], buf[11], buf[12], buf[13]);
//		printf("%c%c%c%c%c%c%c%c\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
//		ft_putstr(buf);
  	ft_bzero(buf, 14);
	read(0, buf, 14);
		printf("%d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10], buf[11], buf[12], buf[13]);
  	ft_bzero(buf, 14);
	}
	return (0);
}
