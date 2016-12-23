/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 02:35:51 by jpepin            #+#    #+#             */
/*   Updated: 2016/01/10 03:17:23 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int			main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	cpid;
	char	buf;

	if (argc != 2)
	{
		fprintf(stderr, "Usage : %s [string]\n", argv[0]);
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (cpid == 1)
	{
		close(pipefd[1]);
		while (read(pipefd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		exit(0);
	}
	else
	{
		close(pipefd[0]);
		write(pipefd[1], argv[1], ft_strlen(argv[1]));
		close(pipefd[1]);
		wait(NULL);
		exit(0);
	}
}
