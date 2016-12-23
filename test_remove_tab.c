/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_remove_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jeremy.aubertpep@yahoo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 05:23:40 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/13 05:46:31 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void the_tab(char ***tab)
{
}

int main(void)
{
  int tab[5][5];
  int i;
  int j;
  i = -1;
  while (++i < 5)
  { j = -1;
    while (++j < 5)
    { tab[i][j] = (i + 1) * (j + 1); }}
  i = -1;
  while (++i < 5)
  { j = -1;
    while (++j < 5)
    { printf("tab[%d][%d]::%d\n", i, j, tab[i][j]); }}}
