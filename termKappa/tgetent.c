/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 20:51:53 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/22 21:32:19 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int					main(void)
{
	char			*TERMTYPE = "xterm-256color";
	int				Erfolg;
	static char		term_buffer [2048];

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
	return (0);
}
