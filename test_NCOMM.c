/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncommands.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:02:05 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/18 10:56:40 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	if (!((multi = ft_strsplit(line, ';'))))
//		return (NULL);

#include "sh1.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

char			***ncommands(char **multi)
{
	int			cur_com;
	char		***ncomm;

	if (!multi || !*multi)
		return (NULL);
	if (!((ncomm = (char***)malloc(sizeof(char**) * (tab_size(multi) + 1)))))
		shell_error(Malloc, "ncomm in ncommands");
	cur_com = -1;
	while (multi[++cur_com])
	{
		ncomm[cur_com] = ft_splitspaces(multi[cur_com]);
		free(multi[cur_com]);
	}
	free(multi);
	ncomm[cur_com] = NULL;
	return (ncomm);
}

int				main(int argc, char **argv, char **envp)
{
	char		***ncomm;
	char		buf;
	char		*line;
	int			i;
	int			j;
	t_par		*params;

	line = NULL;
	params = iparams(envp, ".");
	while (read(1, &buf, 1) && buf != '\n')
		line = ft_concat(line, &buf, 1);
	ncomm = ncommands(ft_strsplit2(line, ';'));
	if (ncomm)
	{
		i = -1;
		while (ncomm[++i])
		{
			ncomm[i] = get_av(params, ncomm[i], 1);
			free(ncomm[i]);
		}
		free(ncomm);
	}
	else
		printf("no command\n");
	return (0);
}
