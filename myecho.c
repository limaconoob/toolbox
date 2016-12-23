/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myecho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:20:53 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/12 09:21:23 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	int j;

	for (j = 0; j < argc; j++)
		printf("argv[%d]: %s\n", j, argv[j]);

	exit(EXIT_SUCCESS);
}
