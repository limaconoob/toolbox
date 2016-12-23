/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_kick_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 05:10:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/06 09:52:19 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_term
{
	int				term_x;
	int				curs_x;
	int				curs_y;
}					t_term;

static char			**tab_realloc(char **tab, int new_size, t_term *term)
{
	char			**tmp;
	int				i;

	tmp = (char**)malloc(sizeof(char*) * (new_size + 1));
	i = -1;
	while (++i < new_size && tab[i])
		tmp[i] = tab[i];
	while (tab[i])
		tab[i] = NULL;
	while (i < new_size)
		tmp[i++] = ft_strnew(term->term_x);
	tmp[new_size] = NULL;
	free(tab);
	return (tmp);
}

char				**kick_back(char **tab, t_term *term)
{
	char			y1;
	char			y2;
	int				y;
	int				x;

	x = term->curs_x;
	y = term->curs_y;
	while (tab[y] && tab[y][x - 1])
	{
		tab[y][x - 1] = tab[y][x];
		x++;
		if (x == term->term_x && tab[y + 1] && !tab[y + 1][1])
		{
			tab[y][x - 1] = tab[y + 1][0];
			tab = tab_realloc(tab, y + 1, term);
			break ;
		}
		else if (x == term->term_x && tab[y + 1])
		{
			tab[y][x - 1] = tab[y + 1][0];
			x = 1;
			y++;
		}
	}
	return (tab);
}

int					main(void)
{
	int				i;
	t_term			*term;
	char			**tab;

	term = (t_term*)malloc(sizeof(t_term));
	term->term_x = 7;
	term->curs_x = 3;
	term->curs_y = 2;
	tab = (char**)malloc(sizeof(char*) * 8);
	i = -1;
	while (++i < 6)
		tab[i] = ft_strdup("Bonjour");
	tab[i++] = ft_strdup("ab");
	tab[i] = NULL;
	tab = kick_back(tab, term);
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
	printf("\n");
	term->curs_x = 6;
	term->curs_y = 5;
	tab = kick_back(tab, term);
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
	printf("\n");
	term->curs_x = 1;
	term->curs_y = 1;
	tab = kick_back(tab, term);
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
	printf("\n");
	term->curs_x = 0;
	term->curs_y = 4;
	tab = kick_back(tab, term);
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
}
