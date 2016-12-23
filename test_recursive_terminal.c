/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_recursive_terminal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 00:10:18 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/15 01:10:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
**	Die Iteration mit while (C) :
**	Die einzige richtige Antwort für ein Wiederanruf das Funktion.
*/
static int		test_iterative_while(int x, int y)
{
	while (y)
	{
		x++;
		y--;
	}
	return (x);
}

/*
**	Die Iteration mit ein Funktion (C) :
**	Dieses Programm lässt sich nicht kompilieren,
**	weil die Stapel nicht freigegeben werden. (SIGSEGV => Stack overflow)
**
**	static int      test_iterative_fonction(int x, int y)
**	{
**		if (!y)
**			return (x);
**		else
**			test_iterative_fonction(x + 1, y - 1);
**		return (0);
**	}
*/

/*
**	Die Rekursion (C) :
**	Dieses Programm lässt sich nicht kompilieren,
**	weil die Stapel nicht freigegeben werden. (SIGSEGV => Stack overflow)
**
**	static int		test_recursive(int x, int y)
**	{
**		if (!y)
**			return (x);
**		else
**			return (1 + test_recursive(x, y - 1));
**	}
*/

/*
**	Die Endrekursion (C) :
**	Dieses Programm lässt sich nicht kompilieren,
**	weil die Stapel nicht freigegeben werden. (SIGSEGV => Stack overflow)
**
**	static int		test_recursive_terminal(int x, int y)
**	{
**		if (!y)
**			return (x);
**		else
**			return (test_recursive_terminal(x + 1, y - 1));
**	}
*/

int				main(void)
{
	int			x;

	x = 0;
//	x = test_recursive_terminal(x, 2147483647);
//	x = test_recursive(x, 2147483647);
	x = test_iterative_while(x, 2147483647);
//	x = test_iterative_fonction(x, 2147483647);
	printf("x::%d\n", x);
	return (0);
}
