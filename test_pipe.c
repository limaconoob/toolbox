/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:43:15 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/16 08:11:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

int main( int argc, char ** argv )
{
//	 create the pipe 
	int pfd[2];
	if (pipe(pfd) == -1)
	{
		printf("pipe failed\n");
		return 1;
	}

	// create the child 
	int pid;
	if ((pid = fork()) < 0)
	{
		printf("fork failed\n");
		return 2;
	}

	if (pid == 0)
	{
		// child 
		close(pfd[1]);//  close the unused write side 
		dup2(pfd[0], 0); // connect the read side with stdin 
		close(pfd[0]);//  close the read side 
		 //execute the process (wc command) 
		execlp("wc", "wc", (char *) 0);
		printf("wc failed");//  if execlp returns, it's an error 
		return 3;
	}
	else
	{
//		 parent 
		close(pfd[0]); // close the unused read side 
		dup2(pfd[1], 1);  //connect the write side with stdout 
		close(pfd[1]);  //close the write side 
	//	 execute the process (ls command) 
		execlp("ls", "ls", (char *)0);
		printf("ls failed");//  if execlp returns, it's an error 
		return 4;
	}
	return 0;
}

/*
int main( int argc, char ** argv )
{
	 create the pipe
	int  pfd[2];
	if (pipe(pfd) == -1)
	{
		printf("pipe failed\n");
		return 1;
	}

	 create the child 
	int  pid;
	if ((pid = fork()) < 0)
	{
		printf("fork failed\n");
		return 2;
	}

	if (pid == 0)
	{
		 child 
		char buffer[BUFSIZ];

		close(pfd[1]);  close write side 

		 read some data and print the result on screen 
		while (read(pfd[0], buffer, BUFSIZ) != 0)
			printf("child reads %s", buffer);

		close(pfd[0]);  close the pipe 
	}
	else
	{
		 parent 
		char buffer[BUFSIZ];

		close(pfd[0]);  close read side

		 send some data into the pipe 
		strcpy(buffer, "HelloWorld\n");
		write(pfd[1], buffer, strlen(buffer)+1);

		close(pfd[1]);  close the pipe 
	}

	return 0;
}


int					main(int argc, char **argv, char **envp)
{
	int				fd[2];
	int				fd2[2];
	pid_t			father;
	char			buf[1];
	int				k;

	fd[1] = 1;
	fd[0] = open("./pipe.txt", O_WRONLY);
	printf("fd[0]::%d\n", fd[0]);
	while (42)
	{
		father = fork();
		if (father > 0)
		{
			while ((read(0, buf, 1)) && buf[0] != '\n')
				;
			wait((void*)0);
		}
		if (father == 0)
		{
			k = pipe(fd);
			printf("k::%d\n", k);
			execve("/bin/ls", argv, envp);
			printf("PROMPT $> ");
			exit(EXIT_SUCCESS);
		}
	}
	(void)close(fd[1]);
	wait(NULL);
}
*/
