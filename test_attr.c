/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 00:56:06 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/18 04:19:27 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/xattr.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	size_t buflen;
	size_t keylen;
	size_t vallen;
	char	*buf;
	char	*key;
	char	*val;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s path\n", argv[0]);
		exit(1);
	}
	buflen = listxattr(argv[1], NULL, 0, XATTR_SHOWCOMPRESSION);
	if (buflen == 0)
	{
		printf("%s has no attributes.\n", argv[1]);
		exit(0);
	}
	buf = malloc(buflen);

	buflen = listxattr(argv[1], buf, buflen, XATTR_SHOWCOMPRESSION);
	if (buflen == -1)
	{
		perror("listxattr");
		exit(1);
	}
	key = buf;
	while (buflen > 0)
	{
		printf("%s : ", key);
		vallen = getxattr(argv[1], NULL, NULL, 0, 0, 1);
		if (vallen == -1)
			perror("getxattr");
		if (vallen > 0)
		{
			val = malloc(vallen + 1);
			if (val == NULL)
			{
				perror("malloc");
				exit(1);
			}
			vallen = getxattr(argv[1], key, val, vallen, 0, 1);
			if (vallen == -1)
				perror("getxattr");
			else
			{
				val[vallen] = 0;
				printf("val : %s\n", val);
			}
			free(val);
		}
		else if (vallen == 0)
			printf("<no value>\n");
	}
	free(buf);
	exit(0);
}
