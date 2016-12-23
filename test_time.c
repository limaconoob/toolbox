/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 04:40:55 by jpepin            #+#    #+#             */
/*   Updated: 2016/01/14 02:21:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

static time_t   get_time(char *file_name)
{
	struct stat sb;

	if (stat(file_name, &sb) == -1)
	{
		perror("stat");
		exit(1);
	}
	return (sb.st_mtime);
}

int		main(void)
{
	DIR		*dirp;
	struct dirent *dp;
	int			i = 0;
	time_t		times[46];
	char		**get;

	dirp = opendir(".");
	if (dirp == NULL)
	{
		perror("opendir");
		return (0);
	}
	printf("ft_ls :\n");
	while ((dp = readdir(dirp)) != NULL)
	{
		times[i] = get_time(dp->d_name);
		printf("time : %zu , ", times[i]);
		printf("file : %s\n", dp->d_name);
		i++;
	}
	get = (char**)malloc(sizeof(char *) * i);
	rewinddir(dirp);
	i = -1;
	printf("\n\n");
	while ((dp = readdir(dirp)) != NULL)
		get[++i] = dp->d_name;
	i = -1;
	while (get[++i])
	{
		printf("time : %zu ",  times[i]);
		printf("%s\n", get[i]);
	}
	get = ft_sort_time(i, get, times);
	i = -1;
	while (get[++i])
		printf("end : %s\n", get[i]);
	free(get);
	(void)closedir(dirp);
	return (1);
}
