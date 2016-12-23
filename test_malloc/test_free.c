/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 06:43:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/21 11:26:15 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

int				main(void)
{
	char **test;
	test = (char**)malloc(sizeof(char*) * 1000);
	int i = -1;
	while (++i < 1000) {
		test[i] = ft_strdup("Bonjour\0");
	}
	i = 0;
	while (test[i]) {
		printf("i: %d test[i]:%s\n", i, test[i]);
		free(test[i]);
		test[i] = ft_strdup("Connard\0");
		printf("i: %d test[i]:%s\n", i, test[i]);
		free(test[i++]);
	}
	free(test);
	return 0;
}
