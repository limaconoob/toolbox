/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dirent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 08:52:29 by jpepin            #+#    #+#             */
/*   Updated: 2016/03/27 09:36:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

int			main(void)
{
	DIR	*dirp;
	dirp = opendir(".");
	struct dirent *dp;
	while ((dp = readdir(dirp))) {
		printf("seekoff:%llu\n", dp->d_seekoff);
		printf("inode:%llu\n", dp->d_ino);
		printf("reclen:%d\n", dp->d_reclen);
		printf("type:%d\n", dp->d_type);
		printf("name:%s\n", dp->d_name);
		printf("\n------------------\n\n");
	}
	(void)closedir(dirp);
	return 0;
}
