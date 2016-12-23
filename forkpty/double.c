/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 09:46:01 by jpepin            #+#    #+#             */
/*   Updated: 2016/08/19 09:59:34 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int      readder(int fd)
{
  char c;
  read(0, &c, 1);
  write(fd, &c, 1);
  return (readder(fd));
}

int       main(void)
{
  int fd = open("/dev/ttys005", O_WRONLY | O_ASYNC);
  return (readder(fd));
}
