/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:50:32 by jpepin            #+#    #+#             */
/*   Updated: 2016/11/08 07:29:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MESSAGE "Bonjour\n"

int       main(void)
{
  int     newfd;
  char    *buff = MESSAGE;
  char    str[10];

  if (fcntl(1, F_GETPATH, str))
    return (42);
  newfd = open(str, O_RDONLY | O_ASYNC);

  printf("%d\n", fcntl(newfd, F_DUPFD));
  printf("%d\n", fcntl(newfd, F_GETFD));
  printf("%d\n", fcntl(newfd, F_GETFL));
  printf("%d\n", fcntl(newfd, F_GETOWN));
  printf("PID::%d, PPID::%d\n", getpid(), getppid());
  printf("%d\n\n", fcntl(newfd, F_GETPATH));
  printf("%d\n", fcntl(1, F_DUPFD));
  printf("%d\n", fcntl(1, F_GETFD));
  printf("%d\n", fcntl(1, F_GETFL));
  printf("%d\n", fcntl(1, F_GETOWN));
  printf("%s\n\n", str);
  while (read(newfd, str, 10) && *str != 'q')
    printf("str::[%s]\n", str);
  if (write(newfd, buff, sizeof(buff)) < 0)
    exit(EXIT_FAILURE);
  (void)close(newfd);
  return EXIT_SUCCESS;
}
