/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 01:57:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/03 09:42:40 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termkappa.h"
#include "../libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

char				*the(void)
{
	char			*name_term;
	char			*term_buffer;
	struct termios	term;

	term_buffer = (char*)malloc(2048);
	name_term = getenv("TERM");
	if (tgetent(NULL, name_term) == -1)
		return (NULL);
	(void)tgetent(term_buffer, name_term);
	if (tcgetattr(0, &term) == -1)
		return (NULL);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (NULL);
	return (term_buffer);
}
