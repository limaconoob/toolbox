/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 05:10:16 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/08 13:48:20 by jpepin           ###   ########.fr       */
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
	while (i < new_size)
		tmp[i++] = ft_strnew(term->term_x);
	tmp[new_size] = NULL;
	free(tab);
	return (tmp);
}

static char			**retour_chariot(int *x, int *y, char **tab, t_term *term)
{
	*x = -1;
	(*y)++;
	ft_putchar('\n');
	if (!tab[*y])
		tab = tab_realloc(tab, *y + 1, term);
	return (tab);
}

char				**push_front(char **tab, t_term *term, char push)
{
	char			y1;
	char			y2;
	int				y;
	int				x;

	x = term->curs_x;
	y = term->curs_y;
	y1 = tab[y][x];
	tab[y][x] = push;
	ft_putchar(push);
	if (x == term->term_x - 1)
		tab = retour_chariot(&x, &y, tab, term);
	while (tab[y])
	{
		y2 = tab[y][x + 1];
		tab[y][x + 1] = y1;
		if (y1)
			ft_putchar(y1);
		y1 = y2;
		x++;
		if (x == term->term_x - 1 && y1)
			tab = retour_chariot(&x, &y, tab, term);
		else if (!tab[y][x])
			break ;
	}
	ft_putchar('\n');
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
	tab[i++] = ft_strdup("Bonjour");
	tab[i] = NULL;
	tab = push_front(tab, term, 'K');
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
	printf("\n");
	term->curs_x = 6;
	term->curs_y = 6;
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	term->curs_x = 2;
	term->curs_y = 2;
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	term->curs_x = 0;
	term->curs_y = 0;
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	tab = push_front(tab, term, 'K');
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
	printf("\n");
	term->curs_x = 0;
	term->curs_y = 0;
	tab = push_front(tab, term, 'K');
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
}

/*
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
	tab[i++] = ft_strdup("Bonjou");
	tab[i] = NULL;
	tab = push_front(tab, term, 'K');
	i = -1;
	while (tab[++i])
	{
		printf("tab[%d]::%s\n", i, tab[i]);
		ft_strdel(&(tab[i]));
	}
	free(tab);
	printf("\n");
	term->curs_x = 6;
	term->curs_y = 6;
	tab = push_front(tab, term, 'K');
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
	printf("\n");
	term->curs_x = 0;
	term->curs_y = 0;
	tab = push_front(tab, term, 'K');
	i = -1;
	while (tab[++i])
		printf("tab[%d]::%s\n", i, tab[i]);
}
*/
