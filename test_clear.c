/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 05:37:08 by jpepin            #+#    #+#             */
/*   Updated: 2016/05/07 05:49:31 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			main(void)
{
	const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
		write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
	return (0);
}
