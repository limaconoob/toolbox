/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:44:08 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/14 03:15:27 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	test_link(void)
{
	struct stat	sb;
	char		*linkname;
	size_t		r;
	char *name = "../goinfre";

	if (lstat(name, &sb) == -1)
	{
		perror("lstat");
		exit(1);
	}
	linkname = (char *)malloc(sb.st_size + 1);
	if (!linkname)
	{
		fprintf(stderr, "Memory\n");
		exit(1);
	}
	r = readlink(name, linkname, sb.st_size + 1);
	if (r <= sb.st_size && r != -1 && linkname != NULL)
	{
		linkname[r] = '\0';
		printf("name::%s\n", name);
		printf("ret::%zu\n", r);
		printf("size::%lld\n", sb.st_size);
		printf("linkname::%s\n", linkname);
	}
	free(linkname);
}

int		main(void) {
	test_link();
	return 0;
}
