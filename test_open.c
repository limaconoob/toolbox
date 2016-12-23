/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 04:05:56 by jpepin            #+#    #+#             */
/*   Updated: 2016/07/01 04:11:25 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/uio.h>
#include <unistd.h>

int				main(void)
{
	int			fd;

	fd = open("./test_open.c", O_CREAT | O_EXCL | O_NONBLOCK);
	printf("fd::%d\n", fd);
}
