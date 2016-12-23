/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:07:15 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/18 10:09:05 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			main(void)
{
	char	**tab;

	tab = (char**)malloc(sizeof(char*));
	tab[0] = NULL;
	free(tab[0]);
	free(tab);
}
