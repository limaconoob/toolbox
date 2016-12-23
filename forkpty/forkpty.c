/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forkpty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 08:26:18 by jpepin            #+#    #+#             */
/*   Updated: 2016/11/06 08:42:55 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <util.h>
#include <termios.h>
#include <fcntl.h>

#include <sys/select.h>
#include <sys/wait.h>

int main()
{

  int master;
  pid_t pid;

  pid = forkpty(&master, NULL, NULL, NULL);
  if (pid < 0) {
    return 1;
  }
  else if (pid == 0) {

    char *args[1] = { "/bin/bash" };
    execvp("/bin/bash", args);
  }
  else {
    struct termios tios;
    tcgetattr(master, &tios);
    tios.c_lflag &= ~(ECHO | ECHONL);
    tcsetattr(master, TCSAFLUSH, &tios);

    for (;;) {
      fd_set          read_fd;
      fd_set          write_fd;
      fd_set          except_fd;
      FD_ZERO(&read_fd);
      FD_ZERO(&write_fd);
      FD_ZERO(&except_fd);
      FD_SET(master, &read_fd);
      FD_SET(STDIN_FILENO, &read_fd);
      select(master+1, &read_fd, &write_fd, &except_fd, NULL);

      char input;
      char output;
      if (FD_ISSET(master, &read_fd))
      {
        if (read(master, &output, 1) != -1)
          write(STDOUT_FILENO, &output, 1);
        else
          break;
      }
      if (FD_ISSET(STDIN_FILENO, &read_fd))
      {
        read(STDIN_FILENO, &input, 1);
        write(master, &input, 1);
      }
    }
  }
  return 0;
}
