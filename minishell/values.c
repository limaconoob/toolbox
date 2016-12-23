/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 19:35:44 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/08 19:43:17 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	printf("RDONLY < %d\n", O_RDONLY);
	(void)close(fd);
	fd = open(argv[1], O_WRONLY);
	printf("WDONLY < %d\n", O_WRONLY);
	(void)close(fd);
	return (0);
}
