/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:51:38 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/01 19:44:59 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
/*
**	----------------------------------------------------------------------------
**
*/
static void		fork_7(void)
{
	pid_t	father;
	char	buf[1];
	int		k;

	k = 0;
	while (42)
	{
		father = fork();
		if (father > 0)
		{
			while ((read(0, buf, 1)) && buf[0] != '\n')
				;
			wait((void*)0);
			k = 1;
			printf("fork 6 MOTHER\n");
		}
		if (father == 0)
		{
			printf("k::%d\n", k);
			k = 0;
			exit(EXIT_SUCCESS);
		}
	}
	wait(NULL);
}

/*
**	----------------------------------------------------------------------------
**	Dies Beispiel zeigt ein prompt, dann wartet für ein Satz 
**	endet mit Enter-drücken.
*/
static void		fork_6(void)
{
	pid_t	father;
	char	buf[1];
	int		k;

	k = 0;
	while (42)
	{
		father = fork();
		if (father > 0)
		{
			while ((read(0, buf, 1)) && buf[0] != '\n')
				;
			wait((void*)0);
			printf("fork 6 MOTHER\n");
		}
		if (father == 0)
		{
			printf("PROMPT $> ");
			exit(EXIT_SUCCESS);
		}
	}
	wait(NULL);
}

/*
**	----------------------------------------------------------------------------
*/
static void		fork_5(void)
{
	pid_t	father;
	char	buf[1];
	int		k;

	k = 0;
	father = fork();
	while (42)
	{
		if (father > 0)
		{
			while (!(read(0, buf, 1)))
				;
			wait((void*)0);
			k = 0;
			printf("fork 5 MOTHER\n");
		}
		if (father == 0)
		{
			k = 1;
			printf("fork 5 DAUGHTER\n");
			exit(EXIT_SUCCESS);
		}
		printf("k::%d\n", k);
	}
	wait(NULL);
}


/*
**	----------------------------------------------------------------------------
**	Dies Beispiel ist in einer Endlosschleife (Vorsicht!)
*/
static void		fork_4(void)
{
	pid_t	father;
	char	buf[1];
	int		k;

	k = 0;
	father = fork();
	while (42)
	{
		if (father > 0)
		{
			while (!(read(0, buf, 1)))
				;
			wait((void*)0);
			k = 0;
			printf("fork 4 MOTHER\n");
		}
		if (father == 0)
		{
			k = 1;
			printf("fork 4 DAUGHTER\n");
		}
		printf("k::%d\n", k);
	}
	wait(NULL);
}


/*
**	----------------------------------------------------------------------------
**
*/
static void		fork_3(void)
{
	pid_t	father;
	char	buf[1];

	while (42)
	{
		father = fork();
		if (father > 0)
		{
			while (!(read(0, buf, 1)))
				;
			wait((void*)0);
			printf("fork 3 MOTHER\n");
		}
		if (father == 0)
		{
			printf("fork 3 DAUGHTER\n");
			exit(EXIT_SUCCESS);
		}
	}
	wait(NULL);
}


/*
**	----------------------------------------------------------------------------
**	Dies Beispiel hört nie auf.
*/
static void		fork_2(void)
{
	pid_t	father;
	char	buf[1];

	father = fork();
	while (42)
	{
		if (father > 0)
		{
			while (!(read(0, buf, 1)))
				;
			wait((void*)0);
			printf("fork 2 MOTHER\n");
		}
		if (father == 0)
		{
			printf("fork 2 DAUGHTER\n");
			wait(NULL);
		}
	}
}


/*
**	----------------------------------------------------------------------------
**	Dies Beispiel ist in einer Endlosschleife (Vorsicht!)
*/
static void		fork_1(void)
{
	pid_t	father;
	char	buf[1];

	father = fork();
	while (42)
	{
		if (father > 0)
		{
			while (!(read(0, buf, 1)))
				;
			wait(NULL);
			printf("fork 1 MOTHER\n");
		}
		if (father == 0)
			printf("fork 1 DAUGHTER\n");
	}
	wait(NULL);
}


/*
**	----------------------------------------------------------------------------
**	Dies Beispiel wartet auf den Enter-drücken
*/
static void		fork_0(char **argv)
{
	pid_t	father;
	char	buf[1];

	father = fork();
	if (father > 0)
	{
		while (!(read(0, buf, 1)))
			;
		wait((void*)0);
	}
	if (father == 0)
		execve("/bin/ls", argv, NULL);
}

/*
**	----------------------------------------------------------------------------
**	Main
*/
int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

//	fork_0(argv);
//	fork_1();
//	fork_2();
//	fork_3();
//	fork_4();
//	fork_5();
//	fork_6();
	fork_7();

	printf("\n-------------------------------------------------------------\n");
	printf("fork 0: Zeigen die ,ls' rückkehrt, dann Warten\n");
	printf("        jemand auf Enter drücken.\n");
	printf("\n-------------------------------------------------------------\n");
	printf("fork 1: Eingeben in ein Endloßschleife in die Tochter.\n");
	printf("\n-------------------------------------------------------------\n");
	printf("fork 2: Eingeben in ein Endloßschleife in die Mutter,\n");
	printf("\n-------------------------------------------------------------\n");
	printf("fork 3: Das ist die rückkehre für diesem Beispiel:\n");
	printf("fork 3 DAUGHTER\n                // <- Ich drücke Enter hier\n");
	printf("fork 3 MOTHER\n");
	printf("fork 3 DAUGHTER\n                // <- Ich drücke Enter hier\n");
	printf("fork 3 MOTHER\nfork 3 DAUGHTER\n");
	printf("Und das Programm Endloß geht weiter.\n");
	printf("\n-------------------------------------------------------------\n");
	printf("fork 4: Eingeben in ein Endloßschleife in die Tochter.\n");
	printf("        ,k' Wert auf 1 bleibt.\n");
	printf("\n-------------------------------------------------------------\n");
	printf("fork 5: Eingeben in ein Endloßschleife in die Mutter.\n");
	printf("        ,k' Wert auf 0 bleibt.\n");
	printf("        Es wartet für Enter-drücken, wie die 3-tte Beispiel.\n");
	printf("\n-------------------------------------------------------------\n");
	printf("fork 6: Das ist die rückkehre für diesem Beispiel:\n");
	printf("PROMPT $> Hallo Leute :)\nfork 6 MOTHER\n");
	printf("PROMPT $>                // <- Ich drücke nur Enter hier\n");
	printf("fork 6 MOTHER\nPROMPT $> ls\nfork 6 MOTHER\nPROMPT $>\n");
	printf("\n-------------------------------------------------------------\n");
	printf("Abschluß: Mann muss ein endloß ,while' und dann\n");
	printf("          die ,fork' benutzt.\n\n");

	return (0);
}
