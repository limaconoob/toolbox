/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piano.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 22:23:26 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/15 10:06:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int			main(void)
{
	setlocale(LC_ALL, "");
	wchar_t c = L'\300'; //écrire l'unicode du caractère pour l'afficher.
/*	while (c < 400) {
		wprintf(L"%lc ", c);
		c++;
	}
	printf("\n");
	c = L'\x2580'; //écrire l'unicode du caractère pour l'afficher.
	while (c < 0x8000) {
		wprintf(L"%lc ", c);
		c++;
	}
*/	c = L'\xE000'; //écrire l'unicode du caractère pour l'afficher.
	printf("\n");
	while (c < 0xE000 + 50) {
		wprintf(L"%lc ", c);
		c++;
	}
	int i = 0;
	while (i < 3) {
		c = L'\x2599';
		wprintf(L"%lc%lc%lc", c, c, c);
		c = L'\x2593';
		wprintf(L"%lc", c);
		c = L'\x259F';
		wprintf(L"%lc%lc", c, c);
		i++;
	}
	printf("\n");
	return (0);
}
