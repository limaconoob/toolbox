/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 20:51:53 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/23 03:50:02 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termcap.h>
#include <curses.h>
#include <term.h>

extern char PC;
extern char * UP;
extern char * BC;
extern short ospeed;

int tgetent(char *bp, const char *name);
int tgetflag(char *id);
int tgetnum(char *id);
char *tgetstr(char *id, char **area);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));

char				*get_buf(void)
{
	char			*TERMTYPE = getenv("TERM");
	int				Erfolg;
	char			*term_buffer;

	term_buffer = (char*)malloc(2048);
	// Gibt es kein TERM Environmentvariable.
	if (TERMTYPE == 0) {
		printf("Geben Sie eine Terminal-Typ mit setenv TERM.\n");
		exit(EXIT_FAILURE);
	}

	// tgetent rückkehrt 1 bei Erfolg
	Erfolg = tgetent(term_buffer, TERMTYPE);

	// Fehlern mit tgetent
	if (Erfolg < 0) {
		printf("Nicht die termcap Datenbank zugreifen können.\n");
		exit(EXIT_FAILURE);
	}
	if (Erfolg == 0) {
		printf("Terminal Typ'%s' ist nicht definiert.\n ", TERMTYPE);
		exit(EXIT_FAILURE);
	}

	printf("Term::%s, Erf::%d, Buf::%s\n", TERMTYPE, Erfolg, term_buffer);
	return (term_buffer);
}

int					main(void)
{
	char			*cl_string;
	char			*cm_string;
	int				height;
	int				width;
	int				auto_wrap;
	char			*buffer;
	char			*temp;

	char			PC;   /* For tputs.  */
	char			*BC;  /* For tgoto.  */
	char			*UP;

	struct termios term;
	if (tcgetattr(0, &term) == -1)
		 return (-1);

	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);

	buffer = (char*)malloc(ft_strlen(get_buf()));

	/* Extract information we will use.  */
	cl_string = tgetstr ("cl", &buffer);
	cm_string = tgetstr ("cm", &buffer);
	auto_wrap = tgetflag ("am");
	height = tgetnum ("li");
	width = tgetnum ("co");

	/* Extract information that termcap functions use.  */
	temp = tgetstr ("pc", &buffer);
	PC = temp ? *temp : 0;
	BC = tgetstr ("le", &buffer);
	UP = tgetstr ("up", &buffer);
	
	printf("buf::%s, cm::%s, am::%d, li::%d, co::%d", buffer, cm_string, auto_wrap, height, width);
	while (42)
		;
}
