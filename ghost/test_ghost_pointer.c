/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ghost_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:48:59 by jpepin            #+#    #+#             */
/*   Updated: 2016/08/11 07:06:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

unsigned int (*(ft_rtr_matrix_tridimension)(void))[3]
{
	static unsigned int tridimension[3];

	return (&tridimension);
}

/*static void					*ghost_pointer(void)
{
	static void				*tab;

	return (&tab);
}*/

int 						main(void)
{
	// -*-*-* HEAP TEST *-*-*-
/*	char *str = (char*)malloc(9);
	str = ft_strcpy(str, "Bonjour\n");
	write(1, str, 8);
	char *tmp = str;
	ft_strdel(&str);
	write(1, tmp, 8);
*/	// *-*-*-*-*-*-*-*-*-*-*-*

	// -*-*-* STACK TEST *-*-*-
	static unsigned int (*str)[3];
//	str = ghost_pointer();
	str = ft_rtr_matrix_tridimension();
	*str[0] = 49;
	*str[1] = 50;
	*str[2] = 51;
	write(1, "\n", 1);
	unsigned char c = (unsigned char)*str[0];
	write(1, &c, 1);
	write(1, "\n", 1);
	c = (unsigned char)*str[1];
	write(1, &c, 1);
	write(1, "\n", 1);
	c = (unsigned char)*str[2];
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	// -*-*-*-*-*-*-*-*-*-*-*-*
	return (0);
}
