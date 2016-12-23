/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termkappa.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:59:44 by jpepin            #+#    #+#             */
/*   Updated: 2016/06/03 02:43:43 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMKAPPA_H
# define TERMKAPPA_H

#include <termios.h>
#include <termcap.h>
#include <term.h>

typedef struct		s_coord
{
	// Größe von das Terminalfenster
	int				term_x;		// Max Spalten
	int				term_y;		// Max Linie

	// Des Position die Kursor
	int				curs_x;
	int				curs_y;
}					t_coord;

int					outc(int c);
char				*the(void);
//void				move_it(int way, int *size);

#endif
