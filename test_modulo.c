/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modulo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 08:16:14 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/19 03:22:30 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int				main(void)
{
	printf("15 mod 4 = %d\n", 15 % 4);
	printf("15 mod 5 = %d\n", 15 % 5);
	printf("4 mod 15 = %d\n", 4 % 15);
	printf("5 mod 15 = %d\n", 5 % 15);
	printf("15 mod 14 = %d\n", 15 % 14);
	printf("14 mod 15 = %d\n", 14 % 15);
	printf("15 mod 28 = %d\n", 15 % 28);
	printf("28 mod 15 = %d\n", 28 % 15);
	printf("19 mod 7 = %d\n", 19 % 7);
	printf("20 mod 7 = %d\n", 20 % 7);
	printf("20 mod 0 = %d\n", 20 % 0);
	printf("0 mod 20 = %d\n", 0 % 20);
	return 0;
}
