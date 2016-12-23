/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 21:34:03 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/28 21:35:32 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_swap_str2(char **av, int i)
{
	char			*tmp;

	tmp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = tmp;
	if (i)
		i--;
	return (i);
}
