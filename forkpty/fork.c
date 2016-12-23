/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 05:33:00 by jpepin            #+#    #+#             */
/*   Updated: 2016/11/08 05:33:16 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
  int fd;
  fd = open("output", O_CREAT|O_TRUNC|O_WRONLY, 0666);
  if(!fork()) {
    /* child */
    write(fd, "hello ", 6);
    _exit(0);
  } else {
    /* parent */
    int status;

    wait(&status);
    write(fd, "world\n", 6);
  }
}
