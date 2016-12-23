/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 09:17:40 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/18 05:00:30 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>

int				main(void)
{
	struct stat sb;
	lstat("/dev/urandom", &sb);
	printf("dev::%u\n", sb.st_dev);
	printf("rdev::%u\n", sb.st_rdev);
	printf("ino::%llu\n", sb.st_ino);
}
