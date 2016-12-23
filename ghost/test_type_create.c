/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_type_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:19:54 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/06 09:43:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_type
{
	unsigned		k : 2;
}					t_type;

void				type_create(void)
{
	t_type			*test;

	printf("sizeof::%lu\n", sizeof(t_type));
	test = (t_type*)malloc(10 * sizeof(t_type));
	test[0].k = 0;
	test[1].k = 5;
	test[2].k = 2;
	test[3].k = 4;
	test[4].k = 5;
	test[5].k = 16;
	test[6].k = 32;
	test[7].k = 3;
	test[8].k = 128;
	test[9].k = 34;
	int			i = -1;
	while (++i < 10)
		printf("tab[%d]::%d\n", i, test[i].k);
}

int					main(void)
{
	type_create();
	return (0);
}
