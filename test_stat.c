/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 04:07:21 by jpepin            #+#    #+#             */
/*   Updated: 2016/01/03 08:34:54 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void		test_stat(char *av)
{
	struct stat sb;

	if (stat(av, &sb) == -1)
	{
		perror("stat");
		exit(1);
	}
	printf("File type :			");
	switch (sb.st_mode & S_IFMT)
	{
		case S_IFWHT: printf("whiteout\n"); break;
		case S_IFBLK: printf("block device\n"); break;
		case S_IFCHR: printf("character device\n"); break;
		case S_IFDIR: printf("directory\n"); break;
		case S_IFIFO: printf("FIFO/pipe\n"); break;
		case S_IFLNK: printf("symlink\n"); break;
		case S_IFREG: printf("regular file\n"); break;
		case S_IFSOCK: printf("socket\n"); break;
		default: printf("unknown?\n"); break;
	}
	printf("Mode :				%lo (octal)\n", (unsigned long) sb.st_mode);
	printf("Link count :			%ld\n", (long) sb.st_nlink);
	printf("Ownership :			UID = %ld, GID = %ld\n", (long)sb.st_uid, (long) sb.st_gid);
	test_pw(sb.st_uid);
	test_gp(sb.st_gid);
	test_mod(sb.st_mode);
	printf("File size :			%lld bytes\n", (long long) sb.st_size);
	printf("Last status change :		%s", ctime(&sb.st_ctime));
	printf("Last file access :		%s", ctime(&sb.st_atime));
	printf("Last file modif' :		%s", ctime(&sb.st_mtime));
}
