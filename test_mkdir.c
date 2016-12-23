/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 04:48:04 by jpepin            #+#    #+#             */
/*   Updated: 2016/11/13 08:44:41 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sysexits.h>
#include <unistd.h>

int main(int argc, char **argv)
{ if (argc != 2)
  { printf("Fehler: Benutzung: ./a.out [Ord-Name]\n");
    return (EX_USAGE); }
  else if (access(argv[1], F_OK) != -1)
  { printf("Fehler: Diese Ordner ist bereits vorhanden\n");
    return (EX_CANTCREAT); }
  else if (mkdir(argv[1], S_IRWXU))
  { printf("Fehler: mkdir könnte nicht %s schaffen\n", argv[1]);
    return (EX_OSERR); }
  return (0); }
