/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 07:11:19 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/20 08:13:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>

void  INThandler(int sig)
{
	char  c;
	signal(sig, SIG_IGN);
	printf("OUCH, did you hit Ctrl-C?\n"
			"Do you really want to quit? [y/n] ");
	c = getchar();
	if (c == 'y' || c == 'Y')
		exit(0);
	else
		signal(SIGINT, INThandler);
	getchar(); // Get new line character
}

int  main(void)
{
	signal(SIGINT, INThandler);
	while (1)
		pause();
	return 0;
}

/*
int 			main(int argc, char **argv)
{
	int			i;

	i = 0;
	while (i++ < 10000000) {
		if (signal(SIGINT , SIG_IGN) == SIG_ERR) {
			printf("Bonjour\n");
		}
	}
	return (0);
}*/
