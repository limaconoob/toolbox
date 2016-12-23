/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 07:27:55 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/01 07:37:51 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_malloc.h"
#include <stdlib.h>
#include <stdio.h>

int				main(void)
{
	char *str = (char*)malloc(8);
	int i = -1;
	while (++i < 7)
		str[i] = 'A';
	str[i] = '\0';
	printf("%s\n", str);
	free(str);
	return 0;
}
