/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ctime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 08:58:37 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/22 09:04:25 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int				main(void) {
	time_t bonjour;
	bonjour = time(NULL);
	char *str;
	str = ctime(&bonjour);
	write(1, str, ft_strlen(str));
//	printf("the_time::%s\n", str);
	return 0;
}
