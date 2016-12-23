/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:44:30 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/02 00:29:52 by jpepin           ###   ########.fr       */
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
	int			len;
	char		buf[4];
	char		*buf_term;

	buf_term = the();
	len = 0;
	while ((ret = read(0, buf, 4))) {
		if (*buf == 'N')
			return (0);
		len += ret;
		printf("len::%d\n", len);
	}
	return (0);
}
