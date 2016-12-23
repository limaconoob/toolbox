/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 01:57:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/25 17:09:31 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termcap.h>
#include <termios.h>
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

int			outc(int c)
{
	ft_putchar(c);
	return (1);
}

/*void		move_it(void)
{
	char	*res;

	if ((res = tgetstr("le", NULL)) == NULL)
		    return ;

	tputs(res, 0, outc);
}*/

/*void			move_it(char *get)
{
	char		*res;
	static int	cmd = 1;
	static int	i = 0;

	if (i == 0)
		cmd = 1;
	else if (i == 80)
		cmd = -1;
	res = tgetstr("cm", &get);
	tputs(tgoto(res, i, 0), 1, outc);
	i += cmd;
}*/

/*void		move_it(char *get)
{
	char	*res;
	static int cmd;
	static int i = 6;

	if (i == 0)
		cmd = 1;
	else if (i == 6)
		cmd = -1;
	res = tgetstr("cm", &get);
	printf("i::%d, cmd::%d, res::%s          \n", i, cmd, res);
	tputs(tgoto(res, i, 0), 1, outc);
	i += cmd;
}*/

void			move_it(char *get, int way)
{
	char		*res;
	int			cmd;
	static int	i = 0;
	static int	c = 0;

	if (i > 0 && way == 68)
		i--;
	else if (i < 79 && way == 67)
		i++;
	else if (c < 28 && way == 66)
		c++;
	else if (c > 0 && way == 65)
		c--;
	res = tgetstr("cm", &get);
	tputs(tgoto(res, i, c), 1, outc);
}

int     voir_touche(char *get)
{
	char     buffer[3];
	static char		*res;

	while (1)
	{
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		read(0, buffer, 3);
		if (buffer[0] == 27)
		{
			move_it(get, buffer[2]);
		}
		
//		res = tgetstr("kl", &get);
//		if (res)
//			move_it(get);
		//		if (buffer[0] == 27)
		//		{
		//			clear_all();
		//			printf("C'est une fleche !\n");
		//		}
//		else if (buffer[0] == 4)
//		{
//			printf("Ctlr+d, on quitte !\n");
//			return (0);
//		}
	}
	return (0);
}

int            	  	main(int ac, char **av, char **env)
{
	char           *name_term = getenv("TERM");
	char            *term_buffer;
	int             Erfolg;
	struct termios term;

	term_buffer = (char*)malloc(2048);
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	Erfolg = tgetent(term_buffer, name_term);
	if (tcgetattr(0, &term) == -1)
		return (-1);

	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	ft_putstr("BONJOUR");
	voir_touche(term_buffer);
	return (0);
}
