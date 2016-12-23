/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wifexit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:51:38 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/20 06:31:57 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

/*
**	----------------------------------------------------------------------------
**	Dies Beispiel zeigt ein prompt, dann wartet für ein Satz 
**	endet mit Enter-drücken.
*/

void			ft_signal(int sig)
{
	if (sig == SIGINT)
	{
		kill(0, sig);
		signal(SIGINT, SIG_IGN);
	}
	else if (sig == SIGCHLD)
		signal(SIGINT, SIG_DFL);
}

static void		fork_6(char **av)
{
	pid_t	father;
	pid_t	w;
	char	buf[1];
	int		k;
	int status;

	k = 0;
	while (42)
	{
		father = fork();
		if (father > 0)
		{
			w = waitpid(father, &status, WUNTRACED | WCONTINUED);
			if (w == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status)) {
				printf("terminé, code=%d\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("tué par le signal %d\n", WTERMSIG(status));
			} else if (WIFSTOPPED(status)) {
				printf("arrêté par le signal %d\n", WSTOPSIG(status));
			} else if (WIFCONTINUED(status)) {
				printf("relancé\n");
			}
			while ((read(0, buf, 1)) && buf[0] != '\n')
				;
			k++;
		}
		if (father == 0)
		{
			printf("PROMPT $> ");
			if (!k)
				execve("/bin/ls", av, NULL);
			else if (k == 1)
				execve("/bin/cat", av, NULL);
			else if (k == 2)
				execve("/bin/ls bonjour", av, NULL);
			else if (k == 3)
				execve("/bin/cat bonjour", av, NULL);
		}
		signal(SIGINT, ft_signal);
		signal(SIGCHLD, ft_signal);
	}
	wait(NULL);
}

/*
**	----------------------------------------------------------------------------
**	Main
*/
int		main(int argc, char **argv)
{
	(void)argc;
	fork_6(argv);
	return (0);
}
