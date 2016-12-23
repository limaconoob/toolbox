/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nomalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:04:34 by jpepin            #+#    #+#             */
/*   Updated: 2016/03/28 06:18:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*nomalloc(size_t t)
{
	return (NULL);
}

#include <stdio.h>

int			main(void)
{
	char *tmp;
	if (!(tmp = (char*)nomalloc(10))) {
		printf("error\n");
		return (0);
	}
	tmp[9] = '\0';
	int i = -1;
	while (++i < 9)
		tmp[i] = 'B';
	printf("tmp:%s\n", tmp);
	return (0);
}
