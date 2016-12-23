/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 07:16:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/01/03 09:17:37 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static void	mod(mode_t *tek)
{
	int		i;

	i = 3;
	while (--i >= 0)
	{
		tek[i] = mod % 8;
		if (tek[i] > 7)
			ft_error();
		mod = mod / 8;
	}
}

void	test_mod(mode_t mod)
{
	mode_t	tek[3];

	mod(tek);
	write(1, "Protection :\t\t\t", 15);
	while (++i < 3)
	{
		if (tek[i] - 4 >= 0)
		{
			tek[i] = tek[i] - 4;
			write(1, "r", 1);
		}
		else
			write(1, "-", 1);
		if (tek[i] - 2 >= 0)
		{
			tek[i] = tek[i] - 2;
			write(1, "w", 1);
		}
		else
			write(1, "-", 1);
		if (tek[i--] >= 0)
			write(1, "x", 1);
		else
			write(1, "-", 1);
	}
	printf("\n");
}
