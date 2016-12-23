/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 02:09:36 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/28 02:29:44 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	int i = access("./test_access.c", X_OK);
	printf("i::%d\n", i);
	i = access("./termKappa", X_OK);
	printf("i::%d\n", i);
	i = access("./access", X_OK);
	printf("i::%d\n", i);
	i = access("./bonjour", X_OK);
	printf("i::%d\n", i);
	i = access("~/work42/ls/prout/", X_OK);
	printf("i::%d\n", i);
	return (0);
}
