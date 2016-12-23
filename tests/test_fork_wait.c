/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 03:21:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/02 01:36:03 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	pid_t	cpid, w;
	int		status;

	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (cpid == 0)
	{
		printf("Child PID is %ld\n", (long)getpid());
		if (argc == 1)
			pause();
		_exit(atoi(argv[1]));
	}
	else
	{
		do
		{
			w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
			if (w == -1)
			{
				perror("waitpid");
				exit(1);
			}
			if (WIFEXITED(status))
				printf("exited, status : %d\n", WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
				printf("killed by signal : %d\n", WTERMSIG(status));
			else if (WIFSTOPPED(status))
				printf("stopped by signal : %d\n", WSTOPSIG(status));
			else if (WIFCONTINUED(status))
				printf("continued\n");
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		exit(0);
	}
}
