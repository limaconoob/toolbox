/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_opendir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 04:40:55 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/23 01:40:21 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int		main(void)
{
	DIR		*dirp;
	struct dirent *dp;
	struct stat sb;
	char *name;
	int minor;
	int major;

	dirp = opendir("/dev/fd/3");
	if (dirp == NULL)
	{
		perror("opendir");
		return (0);
	}
	printf("ft_ls :\n");
	while ((dp = readdir(dirp)) != NULL)
	{
		name = ft_strjoin("/dev/", dp->d_name);
		if (stat(name, &sb) == -1)
			exit(1);
		printf("%s: ", name);
		printf("st_rdev::0x%x ", sb.st_rdev);
		minor = sb.st_rdev & 0xFF;
		major = (sb.st_rdev >> 24) & 0xFF;
		printf("major::%d minor::%d\n", major, minor);
		free(name);
	}
	(void)closedir(dirp);
	return (1);
}
