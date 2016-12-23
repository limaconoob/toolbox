/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sleath_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:48:59 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 02:23:08 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		s_sal
{
	int				salut;
}					t_sal;

typedef struct		s_con
{
	char			*connard;
}					t_con;

typedef struct		s_bon
{
	int				bonjour;
	int				hey;
}					t_bon;

typedef struct		s_par
{
	char			*arbre;
	struct s_bon	**bonjour;
	struct s_sal	**salut;
	struct s_con	*connard;
}					t_par;

unsigned int (*(ft_rtr_matrix_tridimension)(void))[3]
{
	static unsigned int tridimension[3];

	return (&tridimension);
}

static void					*ghost_pointer(void)
{
	static void				*tab;

	return (&tab);
}

unsigned t_par (*(ft_create_params)(void))[1]
{
	static struct s_par params[1];

	static t_sal (*salut)[1];
	salut = ghost_pointer();
	static t_con connard[1];
	connard = ghost_pointer();
	static t_bon (*bonjour)[1];
	bonjour = ghost_pointer();

	(*salut)->salut = 4;
	connard->connard = "N1664\n";
	(*bonjour)->bonjour = 42;
	(*bonjour)->hey = 10;

	params->bonjour = bonjour;
	params->connard = connard;
	params->salut = salut;
	params->arbre = "Baum\n";

	return (&params);
}

int 						main(void)
{
	static unsigned struct s_par (*params)[1];

	params = ft_create_params();
	printf("salut::%d, connard::%s, bonjour::%d, hey::%d\n", (*((*params)->salut)->salut, (*params)->connard->connard, (*((*params)->bonjour))->bonjour, (*((*params)->bonjour))->hey);
/*
	static unsigned int (*str)[3];
	str = ghost_pointer();
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
*/	return (0);
}
