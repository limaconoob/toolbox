/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:21:35 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/12 09:22:15 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char *argv[])
{
	char *newargv[] = { NULL, "hello", "world", NULL };
	char *newenviron[] = { NULL };

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	newargv[0] = argv[1];

	execve(argv[1], newargv, newenviron);
	perror("execve");   /* execve() ne retourne qu’en cas d’erreur */
	exit(EXIT_FAILURE);
}
