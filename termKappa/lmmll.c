/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 01:57:50 by jpepin            #+#    #+#             */
/*   Updated: 2016/09/03 10:25:50 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

int            	  	main(int ac, char **av, char **env)
{
	struct termios term;
  int status;

	struct termios t;
  ioctl(0, TIOCGETA, &t);
  t.c_lflag ^= ~(ICANON);
  t.c_lflag ^= ~(ECHO);
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  ioctl(0, TIOCSETA, &t);
/*	if (tcgetattr(0, &term) == -1)
		return (-1);
  term.c_lflag &= ~(ICANON);
  term.c_lflag &= ~(ECHO);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, &term) == -1)
    return (-1);*/
  char buf;
  while (read(0, &buf, 1))
    ;
  printf("%lu\n", term.c_lflag);
  printf("%lu\n", t.c_lflag);
  return (0);
}
