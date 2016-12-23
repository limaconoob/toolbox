/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 07:58:09 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/07 08:21:43 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct		s_new
{
	int				count;
	struct s_new	*next;
}					t_new;

static t_new		*ielem(int count)
{
	t_new			*elem;

	if (!((elem = (t_new*)malloc(sizeof(t_new)))))
		return (NULL);
	elem->count = count;
	elem->next = NULL;
	return (elem);
}

int					main(void)
{
	t_new			**liste;
	t_new			*elem;
	t_new			*last;
	t_new			*tmp;
	int				count;

	if (!((liste = (t_new**)malloc(sizeof(t_new*)))))
		return (-1);
	elem = ielem(3);
	*liste = elem;
	count = 4;
	while (count < 6) {
		elem->next = ielem(count);
		elem = elem->next;
		count++;
	}

	if ((*liste)->count == 3) {
		tmp = (*liste)->next;
		free(*liste);
		*liste = tmp;
	}

	else {
		last = *liste;
		elem = (*liste)->next;
		count = -1;
		while (elem) {
			if (elem->count == 3) {
				tmp = elem->next;
				free(elem);
				last->next = tmp;
				elem = tmp;
				continue ;
			}
			elem = elem->next;
			last = last->next;
		}
	}

	while (*liste) {
		printf("liste->count::%d\n", (*liste)->count);
		tmp = (*liste)->next;
		free(*liste);
		*liste = tmp;
	}
	free(liste);
	return (0);
}
